import cgi
import os
import pickle
import logging

from google.appengine.api import users
from google.appengine.ext import webapp
from google.appengine.ext.webapp.util import run_wsgi_app
from google.appengine.ext import db
from google.appengine.ext.webapp import template
from google.appengine.api import memcache

MEMCACHE_GREETINGS = 'greetings'

class Greeting(db.Model):
  name = db.StringProperty(multiline=False)
  author = db.UserProperty()
  content = db.StringProperty(multiline=True)
  date = db.DateTimeProperty(auto_now_add=True)

class MainPage(webapp.RequestHandler):
  def get(self):
    logging.debug("In MainPage handler");
    greetingsString = memcache.get(MEMCACHE_GREETINGS)
    if greetingsString is not None:
      logging.info("Retrieved greetings from memcache")
      greetings = pickle.loads(greetingsString)
    else:
      logging.info("No greetings in memcache, re-querying datastore")
      greetings_query = Greeting.all().order('-date')
      greetings = greetings_query.fetch(10)
      if not memcache.set(MEMCACHE_GREETINGS, pickle.dumps(greetings)):
        logging.error("Memcache set failed.")

    if users.get_current_user():
      url = users.create_logout_url(self.request.uri)
      url_linktext = 'Sign Out'
    else:
      url = users.create_login_url(self.request.uri)
      url_linktext = 'Sign in'

    template_values = {
      'greetings': greetings,
      'url': url,
      'url_linktext': url_linktext,
      }

    path = os.path.join(os.path.dirname(__file__),
            os.path.join('templates','guestbook.html'))
    self.response.out.write(template.render(path, template_values))

class Guestbook(webapp.RequestHandler):
  def post(self):
    greeting = Greeting()

    if users.get_current_user():
      greeting.author = users.get_current_user()
    try:
      greeting.name = self.request.get('author')
    except KeyError:
      greeting.name = None
    greeting.content = self.request.get('content')
    greeting.put()
    memcache.delete(MEMCACHE_GREETINGS)
    self.redirect('/guestbook')

application = webapp.WSGIApplication(
                                     [('/guestbook', MainPage),
                                      ('/guestbook/sign', Guestbook)],
                                     debug=True)

def main():
  run_wsgi_app(application)

if __name__ == "__main__":
  main()
