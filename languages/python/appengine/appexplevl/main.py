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
        msg = """Hello %s! \n
        Your Experience is %s.\n
        Your Level is %s.\n
        <a href="/play">Play again.</a>
        """
        if users.get_current_user():
            url = users.create_logout_url(self.request.uri)
        else:
            self.redirect(users.create_login_url(self.request.uri))

        game_query = Experience.all().ancestor(game_key())
        mygame = game_query.filter('user = ',users.get_current_user())
        result = mygame.get()

        user = users.get_current_user()
        self.response.out.write(repr(mygame))
        if result:
            self.response.out.write(repr(result))
            self.response.out.write("hello")
            self.response.out.write(type(result))
            self.response.out.write(dir(result))
            score = result.exp
            level = result.lvl
            #score = mygame.exp
            #level = mygame.lvl
            #mygame.exp = mygame.exp + 1
            #mygame.lvl = mygame.lvl + 1
            #mygame.put()
        else:
            self.response.out.write("world")
            expobj = Experience(parent=game_key())
            expobj.user = users.get_current_user()
            expobj.exp = 1
            expobj.lvl = 1
            expobj.put()
            score = expobj.exp
            level = expobj.lvl

        self.response.out.write(msg % (user,score,level))

def main():
    application = webapp.WSGIApplication([('/', MainHandler),
                                          ('/play', GameHandler)],
                                         debug=True)
    util.run_wsgi_app(application)


if __name__ == '__main__':
    main()
