import cgi
import datetime
import wsgiref.handlers
import random

from google.appengine.ext import db
from google.appengine.api import users
from google.appengine.ext import webapp

class TodoList(db.Model):
    daykey = db.StringProperty(required=True)
    user = db.UserProperty(required=True)

class TodoItem(db.Model):
    user = db.UserProperty(required=True)
    date = db.DateTimeProperty(auto_now_add=True)
    belongs_to = db.ReferenceProperty(TodoList)
    description = db.StringProperty(multiline=True)
    rating = db.IntegerProperty(required=True)
    score = db.IntegerProperty(default=0)

class CreateTodo(webapp.RequestHandler):
    def get(self):
        #today = datetime.datetime.today().strftime('%d-%m-%Y')
        today = str(random.randint(1,3))
        user = users.get_current_user()
        if user:
            username = user
            Query_TodoList = db.Query(TodoList)
            Query_Filtered = Query_TodoList.filter('daykey =', today).filter('user =',username)
            if not Query_Filtered.fetch(limit=1):
                todolist = TodoList(daykey=today, user=username)
                todolist.put()
            else:
                todolist = Query_Filtered.fetch(limit=1)[0]
            user_rating = random.randint(1,10)
            user_score = random.randint(1,10)
            todoitem = TodoItem(user=username,belongs_to=todolist,description='something',rating=user_rating,score=user_score)
            todoitem.put()
            self.response.out.write('todo item written')
        else:
            self.redirect(users.create_login_url(self.request.uri))

class UpdateTodo(webapp.RequestHandler):
    def get(self):
        self.response.out.write("hello,world")

application = webapp.WSGIApplication([
    ('/', CreateTodo),
    ('/update',UpdateTodo)],debug=True)

def main():
  wsgiref.handlers.CGIHandler().run(application)

if __name__ == '__main__':
  main()
