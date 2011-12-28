import setapipaths
import sys
print sys.path

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

obj1 = TodoItem()
