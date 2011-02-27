#!/usr/bin/env python

"""Shalgreetings.com website.

Choose a very nice high quality photo.
Apply picnik transformations and send it to your friend.
"""

import os
from google.appengine.api import urlfetch
from google.appengine.api import users
from google.appengine.ext import webapp
from google.appengine.ext.webapp import util
from google.appengine.ext.webapp import template
from google.appengine.ext import db


class MainHandler(webapp.RequestHandler):
    def get(self):
        """Get the cards and display it."""
        # We are not using any template features at the moment.
        values = { }

        template_loc = os.path.join(os.path.dirname(__file__),'templates',
                'index.html')

        self.response.out.write(template.render(template_loc, values))


def main():
    application = webapp.WSGIApplication([('/', MainHandler)],
                                         debug=True)
    util.run_wsgi_app(application)


if __name__ == '__main__':
    main()
