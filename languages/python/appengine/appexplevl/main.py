import cgi
import datetime
import urllib
import wsgiref.handlers

from google.appengine.ext import webapp
from google.appengine.ext.webapp import util
from google.appengine.ext import db
from google.appengine.api import users


class Experience(db.Model):
    user = db.UserProperty()
    exp = db.IntegerProperty()
    lvl = db.IntegerProperty()

def game_key():
    return db.Key.from_path('Game','default')

class MainHandler(webapp.RequestHandler):
    def get(self):
        self.response.out.write('<a href="/play">Play Game</a>')

class GameHandler(webapp.RequestHandler):
    def get(self):
        # Display the score and experience.
        # Increment the score and experience at each click.
        msg = """<h2>Hello %s! </h2>\n
        <p>Your Experience is <b>%s.</b></p>\n
        <p>Your Level is <b>%s.</b></p>\n
        <hr>
        <b><a href="/play">Play again.</a>.</b><br>
        <p>Score 10 in Experience to Level up.</p>
        <hr>
        <a href="%s">logout</a>
        """
        url = users.create_logout_url(self.request.uri)

        if not users.get_current_user():
            self.redirect(users.create_login_url(self.request.uri))

        game_query = Experience.all().ancestor(game_key())
        mygame = game_query.filter('user = ',users.get_current_user())
        result = mygame.get()
        user = users.get_current_user()
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
            expobj.user = users.get_current_user()
            expobj.exp = 1
            expobj.lvl = 0
            expobj.put()
            score = expobj.exp
            level = expobj.lvl

        self.response.out.write(msg % (user,score,level, url))

def main():
    application = webapp.WSGIApplication([('/', MainHandler),
                                          ('/play', GameHandler)],
                                         debug=True)
    util.run_wsgi_app(application)


if __name__ == '__main__':
    main()
