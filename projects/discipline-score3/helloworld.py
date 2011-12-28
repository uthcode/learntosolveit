import cgi
import datetime
import wsgiref.handlers
import random

from google.appengine.ext import db
from google.appengine.api import users
from google.appengine.ext import webapp
from google.appengine.ext.webapp.util import run_wsgi_app

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
                # there should be only one list for a user for a day.
                todolist = Query_Filtered.get()
            user_rating = random.randint(1,10)
            user_score = random.randint(1,10)
            todoitem = TodoItem(user=username,belongs_to=todolist,description='something',rating=user_rating,score=user_score)
            todoitem.put()
            self.response.out.write('todo item written')
        else:
            self.redirect(users.create_login_url(self.request.uri))

class UpdateTodo(webapp.RequestHandler):
    def get(self):
        user = users.get_current_user()
        if user:
            username = user
            Query_TodoItem = db.Query(TodoItem)
            description = self.request.get('description',default_value='something')
            rating = int(self.request.get('rating',default_value=10))
            Query_Filtered = Query_TodoItem.filter('user =',username).filter('description =', description).filter('rating =',rating)
            if not Query_Filtered.fetch(limit=1):
                self.response.out.write('You do not have such a Todo Item')
            else:
                todoitem = Query_Filtered.get()
                score = int(self.request.get('score'))
                todoitem.score = score
                todoitem.put()
                self.response.out.write('Updated Score.')
        else:
            self.redirect(users.create_login_url(self.request.uri))

application = webapp.WSGIApplication([
    ('/', CreateTodo),
    ('/update',UpdateTodo)],debug=True)

def main():
    run_wsgi_app(application)
    #wsgiref.handlers.CGIHandler().run(application)

if __name__ == '__main__':
  main()
