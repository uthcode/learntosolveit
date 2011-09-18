from google.appengine.ext import db

class Task(db.Model):
    taskid = db.IntegerProperty()
    fromtime = db.TimeProperty(required=True)
    totime = db.TimeProperty(required=True)
    taskdetails = db.StringProperty(required=True)
    done = db.BooleanProperty()
    rating = db.IntegerProperty(required=True)
    score = db.IntegerProperty()

class Daily(Score):
    timestamp = db.DateTimeProperty(auto_now_add=True)
    dayscore = db.IntegerProperty()
