#!/usr/bin/env python
#
# Copyright 2008 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""A simple Google App Engine wiki application.

The main distinguishing feature is that editing is in a WYSIWYG editor
rather than a text editor with special syntax.  This application uses
google.appengine.api.datastore to access the datastore.  This is a
lower-level API on which google.appengine.ext.db depends.
"""

__author__ = 'Bret Taylor'

import cgi
import datetime
import os
import re
import sys
import urllib
import urlparse

from google.appengine.api import datastore
from google.appengine.api import datastore_types
from google.appengine.api import users
from google.appengine.ext import webapp
from google.appengine.ext.webapp import template
from google.appengine.ext.webapp.util import run_wsgi_app
import datetime
import conf
import random

# Set to true if we want to have our webapp print stack traces, etc
_DEBUG = True


class BaseRequestHandler(webapp.RequestHandler):
  """Supplies a common template generation function.

  When you call generate(), we augment the template variables supplied with
  the current user in the 'user' variable and the current webapp request
  in the 'request' variable.
  """
  def generate(self, template_name, template_values={}):
    count = datetime.datetime(2010,8,29) - datetime.datetime.today()
    if count.days > 0:
        count = str(count.days) + ' days to go!'
    elif count.days == 0:
        count = 'Today!'
    else:
        count = 'Infinity and Beyond'
    #quote = 'Love is the condition in which the happiness of another person \
    #essential to your own.  ~Robert Heinlein'
    quote = random.choice(conf.quotes)
    values = {
      'request': self.request,
      'user': users.get_current_user(),
      'login_url': users.create_login_url(self.request.uri),
      'logout_url': users.create_logout_url(self.request.uri),
      'application_name': 'Dum Dum Dum',
      'count': count,
      'quote': quote,
    }
    values.update(template_values)
    directory = os.path.dirname(__file__)
    path = os.path.join(directory, os.path.join('templates', template_name))
    self.response.out.write(template.render(path, values, debug=_DEBUG))
  
  def head(self, *args):
    pass
  
  def get(self, *args):
    pass
    
  def post(self, *args):
    pass


class WikiPage(BaseRequestHandler):
  """Our one and only request handler.

  We first determine which page we are editing, using "MainPage" if no
  page is specified in the URI. We then determine the mode we are in (view
  or edit), choosing "view" by default.

  POST requests to this handler handle edit operations, writing the new page
  to the datastore.
  """
  def get(self, page_name):
    """Handle HTTP GET requests throughout the application, used to present
    the view and edit modes of wiki pages.
    
    Args:
      page_name: The wikified name of the current page.
    """
    # Load the main page by default
    if not page_name:
      page_name = 'MainPage'
    page = Page.load(page_name)

    # Default to edit for pages that do not yet exist
    if not page.entity:
      mode = 'edit'
    else:
      modes = ['view', 'edit']
      mode = self.request.get('mode')
      if not mode in modes:
        mode = 'view'

    # User must be logged in to edit
    if mode == 'edit' and not users.get_current_user():
      self.redirect(users.create_login_url(self.request.uri))
      return

    # Genertate the appropriate template
    self.generate(mode + '.html', {
      'page': page,
    })

  def post(self, page_name):
    """Handle HTTP POST requests throughout the application, used to handle
    posting new or edited wiki pages.
    
    Args:
      page_name: The wikified name of the current page.
    """
    # User must be logged in to edit
    if not users.get_current_user():
      # The GET version of this URI is just the view/edit mode, which is a
      # reasonable thing to redirect to
      self.redirect(users.create_login_url(self.request.uri))
      return

    # We need an explicit page name for editing
    if not page_name:
      self.redirect('/')

    # Create or overwrite the page
    page = Page.load(page_name)
    page.content = self.request.get('content')
    page.save()
    self.redirect(page.view_url())


class Page(object):
  """Our abstraction for a Wiki page.

  We handle all datastore operations so that new pages are handled
  seamlessly. To create OR edit a page, just create a Page instance and
  clal save().
  """
  def __init__(self, name, entity=None):
    self.name = name
    self.entity = entity
    if entity:
      self.content = entity['content']
      if entity.has_key('user'):
        self.user = entity['user']
      else:
        self.user = None
      self.created = entity['created']
      self.modified = entity['modified']
    else:
      # New pages should start out with a simple title to get the user going
      now = datetime.datetime.now()
      self.content = '<h1>%s</h1>' % (cgi.escape(name),)
      self.user = None
      self.created = now
      self.modified = now

  def entity(self):
    return self.entity

  def edit_url(self):
    return '/%s?mode=edit' % (self.name,)

  def view_url(self):
    return '/' + self.name

  def wikified_content(self):
    """Applies our wiki transforms to our content for HTML display.

    We auto-link URLs, link WikiWords, and hide referers on links that
    go outside of the Wiki.
    
    Returns:
      The wikified version of the page contents.
    """
    transforms = [
      AutoLink(),
      WikiWords(),
      HideReferers(),
    ]
    content = self.content
    for transform in transforms:
      content = transform.run(content)
    return content

  def save(self):
    """Creates or edits this page in the datastore."""
    now = datetime.datetime.now()
    if self.entity:
      entity = self.entity
    else:
      entity = datastore.Entity('Page')
      entity['name'] = self.name
      entity['created'] = now
    entity['content'] = datastore_types.Text(self.content)
    entity['modified'] = now

    if users.get_current_user():
      entity['user'] = users.get_current_user()
    elif entity.has_key('user'):
      del entity['user']

    datastore.Put(entity)

  @staticmethod
  def load(name):
    """Loads the page with the given name.

    Returns:
      We always return a Page instance, even if the given name isn't yet in
      the database. In that case, the Page object will be created when save()
      is called.
    """
    query = datastore.Query('Page')
    query['name ='] = name
    entities = query.Get(1)
    if len(entities) < 1:
      return Page(name)
    else:
      return Page(name, entities[0])

  @staticmethod
  def exists(name):
    """Returns true if the page with the given name exists in the datastore."""
    return Page.load(name).entity


class Transform(object):
  """Abstraction for a regular expression transform.

  Transform subclasses have two properties:
     regexp: the regular expression defining what will be replaced
     replace(MatchObject): returns a string replacement for a regexp match

  We iterate over all matches for that regular expression, calling replace()
  on the match to determine what text should replace the matched text.

  The Transform class is more expressive than regular expression replacement
  because the replace() method can execute arbitrary code to, e.g., look
  up a WikiWord to see if the page exists before determining if the WikiWord
  should be a link.
  """
  def run(self, content):
    """Runs this transform over the given content.

    Args:
      content: The string data to apply a transformation to.

    Returns:
      A new string that is the result of this transform.
    """
    parts = []
    offset = 0
    for match in self.regexp.finditer(content):
      parts.append(content[offset:match.start(0)])
      parts.append(self.replace(match))
      offset = match.end(0)
    parts.append(content[offset:])
    return ''.join(parts)


class WikiWords(Transform):
  """Translates WikiWords to links.

  We look up all words, and we only link those words that currently exist.
  """
  def __init__(self):
    self.regexp = re.compile(r'[A-Z][a-z]+([A-Z][a-z]+)+')

  def replace(self, match):
    wikiword = match.group(0)
    if Page.exists(wikiword):
      return '<a class="wikiword" href="/%s">%s</a>' % (wikiword, wikiword)
    else:
      return wikiword


class AutoLink(Transform):
  """A transform that auto-links URLs."""
  def __init__(self):
    self.regexp = re.compile(r'([^"])\b((http|https)://[^ \t\n\r<>\(\)&"]+' \
                             r'[^ \t\n\r<>\(\)&"\.])')

  def replace(self, match):
    url = match.group(2)
    return match.group(1) + '<a class="autourl" href="%s">%s</a>' % (url, url)


class HideReferers(Transform):
  """A transform that hides referers for external hyperlinks."""

  def __init__(self):
    self.regexp = re.compile(r'href="(http[^"]+)"')

  def replace(self, match):
    url = match.group(1)
    scheme, host, path, parameters, query, fragment = urlparse.urlparse(url)
    url = 'http://www.google.com/url?sa=D&amp;q=' + urllib.quote(url)
    return 'href="%s"' % (url,)


def main():
  application = webapp.WSGIApplication([('/(.*)', WikiPage)], debug=_DEBUG)
  run_wsgi_app(application)


if __name__ == '__main__':
  main()
