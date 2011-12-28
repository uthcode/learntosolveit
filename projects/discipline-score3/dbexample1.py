import setapipaths # Sets the paths to google appengine apis
import sys

from google.appengine.ext import db

class TodoList(db.Model):
    name = db.StringProperty(required=True)

class TodoItem(db.Model):
    user = db.UserProperty(required=True)
    date = db.DateTimeProperty(auto_now_add=True)
    belongs_to = db.Reference(TodoList)
    description = db.StringProperty(multiline=True)
    rating = db.IntegerProperty(required=True)
    score = db.IntegerProperty(required=True)

todolist = TodoList()
todolist.name = "firstline"
todolist.put()

obj1 = TodoItem(user='senthil',belongs_to=todolist.key(),description="something",rating=10,score=5)
obj1.put()
