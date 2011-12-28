import cgi
import datetime
import wsgiref.handlers

from google.appengine.ext import db
from google.appengine.api import users
from google.appengine.ext import webapp

class TodoList(db.Model):
    name = db.StringProperty(required=True)

class TodoItem(db.Model):
    user = db.StringProperty(required=True)
    date = db.DateTimeProperty(auto_now_add=True)
    belongs_to = db.ReferenceProperty(TodoList)
    description = db.StringProperty(multiline=True)
    rating = db.IntegerProperty(required=True)
    score = db.IntegerProperty(required=True)

class MainPage(webapp.RequestHandler):
    todolist = TodoList(name='firstlist')
    todolist.put()
    todoitem = TodoItem(user='senthil',belongs_to=todolist,description='something',rating=10,score=5)
    todoitem.put()
    self.response.out.write('todo item written')

application = webapp.WSGIApplication([
  ('/', MainPage),
], debug=True)


def main():
  wsgiref.handlers.CGIHandler().run(application)

if __name__ == '__main__':
  main()
