#!/usr/bin/env python

"""A barebones AppEngine application that uses Facebook for login."""

FACEBOOK_APP_ID = "280237022005951"
FACEBOOK_APP_SECRET = "6ddb8ceb6cefc3ab1aa3adcec6a9e064"

import facebook
import os.path
import wsgiref.handlers

from google.appengine.ext import db
from google.appengine.ext import webapp
from google.appengine.ext.webapp import util
from google.appengine.ext.webapp import template


class User(db.Model):
    id = db.StringProperty(required=True)
    created = db.DateTimeProperty(auto_now_add=True)
    updated = db.DateTimeProperty(auto_now=True)
    name = db.StringProperty(required=True)
    profile_url = db.StringProperty(required=True)
    access_token = db.StringProperty(required=True)


class Experience(db.Model):
    user = db.UserProperty()
    exp = db.IntegerProperty()
    lvl = db.IntegerProperty()

def game_key():
    return db.Key.from_path('Game','default')

class BaseHandler(webapp.RequestHandler):
    """Provides access to the active Facebook user in self.current_user

    The property is lazy-loaded on first access, using the cookie saved
    by the Facebook JavaScript SDK to determine the user ID of the active
    user. See http://developers.facebook.com/docs/authentication/ for
    more information.
    """
    @property
    def current_user(self):
        if not hasattr(self, "_current_user"):
            self._current_user = None
            cookie = facebook.get_user_from_cookie(
                self.request.cookies, FACEBOOK_APP_ID, FACEBOOK_APP_SECRET)
            if cookie:
                # Store a local instance of the user data so we don't need
                # a round-trip to Facebook on every request
                user = User.get_by_key_name(cookie["uid"])
                if not user:
                    graph = facebook.GraphAPI(cookie["access_token"])
                    profile = graph.get_object("me")
                    user = User(key_name=str(profile["id"]),
                                id=str(profile["id"]),
                                name=profile["name"],
                                profile_url=profile["link"],
                                access_token=cookie["access_token"])
                    user.put()
                elif user.access_token != cookie["access_token"]:
                    user.access_token = cookie["access_token"]
                    user.put()
                self._current_user = user
        return self._current_user

class GameHandler(BaseHandler):
    def get(self):
        current_fb_user = self.current_user
        game_query = Experience.all().ancestor(game_key())
        mygame = game_query.filter('user = ', current_fb_user)
        result = mygame.get()

        if result:
            score = result.exp
            level = result.lvl
            result.exp = score + 1
            if (result.exp % 10) == 0:
                result.lvl = level + 1
                result.exp = 0
            result.put()
        else:
            expobj = Experience(parent=game_key())
            expobj.user = current_fb_user
            expobj.exp = 1
            expobj.lvl = 0
            expobj.put()
            score = expobj.exp
            level = expobj.lvl

        path = os.path.join(os.path.dirname(__file__), "game.html")
        args = dict(current_user=self.current_user,
                    facebook_app_id=FACEBOOK_APP_ID,
                    current_score = score,
                    current_level = level
                    )
        self.response.out.write(template.render(path, args))

class HomeHandler(BaseHandler):
    def post(self):
        path = os.path.join(os.path.dirname(__file__), "home.html")
        args = dict(current_user=self.current_user,
                    facebook_app_id=FACEBOOK_APP_ID,
                    )
        self.response.out.write(template.render(path, args))


def main():
    util.run_wsgi_app(webapp.WSGIApplication([(r"/", HomeHandler),
                                              (r"/play", GameHandler)]))


if __name__ == "__main__":
    main()
