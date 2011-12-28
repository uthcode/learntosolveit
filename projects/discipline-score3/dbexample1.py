from google.appengine.ext import db

class TodoItem(db.Model):
    user = db.UserProperty()
    description = db.StringProperty(multiline=True)
    date = db.DateTimeProperty(auto_now_add=True)
    rating = db.IntegerProperty()
    score = db.IntegerProperty()
