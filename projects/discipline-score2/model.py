from google.appengine.ext import db

class Task(db.Model):
    taskid = db.IntegerProperty()
    fromtime = db.DateTimeProperty()
    totime = db.DateTimeProperty()
    taskdetails = db.StringProperty()
    done = db.BooleanProperty()

class Rating(Task):
    rating = db.IntegerProperty()

class Score(Rating):
    score = db.IntegerProperty()

class Daily(Score):
    timestamp = db.DateTimeProperty(auto_now_add=True)
    dayscore = db.IntegerProperty()
