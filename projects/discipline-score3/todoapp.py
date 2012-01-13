import cgi
import datetime
import random
import urllib
import pytz

from pytz import timezone

from google.appengine.ext import db
from google.appengine.api import users
from google.appengine.ext import webapp
from google.appengine.ext.webapp.util import run_wsgi_app

class TimezoneInfo(db.Model):
    timezoneinfo = db.StringProperty(default='')
    user = db.UserProperty(required=True)

class TodoList(db.Model):
    daykey = db.StringProperty(required=True)
    user = db.UserProperty(required=True)
    dayscore = db.FloatProperty(default=0.0)

class TodoItem(db.Model):
    user = db.UserProperty(required=True)
    date = db.DateTimeProperty(auto_now_add=True)
    belongs_to = db.ReferenceProperty(TodoList)
    description = db.StringProperty(multiline=True)
    rating = db.IntegerProperty(required=True, default=0)
    score = db.IntegerProperty(default=0)

class SetTimeZone(webapp.RequestHandler):

    def get(self):
        username = users.get_current_user()
        if username:
            self.response.out.write("<html>")
            self.response.out.write("<title>discipline-score timezone.</title>")
            self.response.out.write("<h2>Please set your timezone.</h2>")
            self.response.out.write("<i>Like Asia/Singpore or Asia/Kolkata</h2>")
            self.response.out.write("""
            <form action="/settimezone" method="post"/>
            <div>TimeZone</br><textarea name="timezoneinfo" label="timezone" rows="1" cols="50"></textarea></div>
            <div><input type="submit" value="submit"></div>
            </form>
            """)
            self.response.out.write("</html>")
        else:
            self.redirect(users.create_login_url(self.request.uri))

    def post(self):
        username = users.get_current_user()
        timezoneinfo = self.request.get('timezoneinfo',default_value='UTC')
        if username:
            try:
                timezone(timezoneinfo)
            except pytz.UnknownTimeZoneError, e:
                self.response.out.write("<h2>Unknown Timezone</h2>")
                self.response.out.write("</br>")
                self.response.out.write("<h2>Please <a href='/settimezone'>try again</a>.</h2>")
            else:
                timezoneinfo_obj = db.Query(TimezoneInfo)
                filtered_timezoneinfo = timezoneinfo_obj.filter('user =', username)

                if not filtered_timezoneinfo.fetch(limit=1):
                    settimezone = TimezoneInfo(user=username, timezoneinfo=timezoneinfo)
                    settimezone.put()
                else:
                    settimezone = filtered_timezoneinfo.get()
                    settimezone = TimezoneInfo(user=username)
                    settimezone.timezoneinfo = timezoneinfo
                    settimezone.put()

                self.redirect('/')
        else:
            self.redirect(users.create_login_url(self.request.uri))

class UpdateTodo(webapp.RequestHandler):
    def get(self):
        username = users.get_current_user()
        if username:
            Query_TodoItem = db.Query(TodoItem)
            description = self.request.get('description',default_value='')
            rating = int(self.request.get('rating',default_value='10'))
            Query_Filtered = Query_TodoItem.filter('user =',username).filter('description =', description).filter('rating =',rating)
            if not Query_Filtered.fetch(limit=1):
                self.response.out.write('You do not have such a Todo Item')
            else:
                todoitem = Query_Filtered.get()
                score = int(self.request.get('score'))
                todoitem.score = score
                todoitem.put()
                self.redirect('/')
        else:
            self.redirect(users.create_login_url(self.request.uri))

    def post(self):
        username = users.get_current_user()
        if username:
            Query_TodoItem = db.Query(TodoItem)
            description = self.request.get('description',default_value='something')
            rating = int(self.request.get('rating',default_value='10'))
            Query_Filtered = Query_TodoItem.filter('user =',username).filter('description =', description).filter('rating =',rating)
            if not Query_Filtered.fetch(limit=1):
                self.response.out.write('You do not have such a Todo Item')
            else:
                todoitem = Query_Filtered.get()
                score = int(self.request.get('score'))
                todoitem.score = score
                todoitem.put()
                self.redirect('/')
        else:
            self.redirect(users.create_login_url(self.request.uri))


class MainPage(webapp.RequestHandler):
    def get(self):
        self.response.out.write("<html>")
        self.response.out.write("<title>discipline score</title>")
        username = users.get_current_user()
        if username:
            timezoneinfo_obj = db.Query(TimezoneInfo)
            filtered_timezoneinfo = timezoneinfo_obj.filter('user =', username)

            if not filtered_timezoneinfo.fetch(limit=1):
                self.redirect('/settimezone')
            else:

                usertimezone = filtered_timezoneinfo.get()
                user_tzinfo = timezone(usertimezone.timezoneinfo)

                # Make it timezone aware

                today = self.request.get('day',default_value='')

                if not today:
                    today = datetime.datetime.now(user_tzinfo).strftime('%d%m%Y')
                    displaydate = datetime.datetime.now(user_tzinfo).strftime("%d-%m-%Y")
                else:
                    displaydate = today[:2] + '-' + today[2:4] + '-' + today[4:]

                self.response.out.write("<h3>Date - %s</h3>" % displaydate)
                self.response.out.write("""<h3>Add a <a href="/new">new todo</a>?</h3>""")
                todolist_queryobj = db.Query(TodoList)
                filtered_todolist = todolist_queryobj.filter('daykey =', today).filter('user =', username)
                if not filtered_todolist.fetch(limit=1):
                    todolist = TodoList(daykey=today, user=username)
                    self.response.out.write("""</br>No todos for you yet.</br>""")
                    self.response.out.write("""Why not create one <a href="/new">now</a>?""")
                else:
                    # there should be only one list for a user for a day.
                    todolist = filtered_todolist.get()
                    todoitem_queryobj = db.Query(TodoItem)
                    filtered_todoitem = todoitem_queryobj.filter('belongs_to =',
                            todolist).filter('user =', username)
                    self.response.out.write("<ul>")
                    total_rating_for_day = 0
                    total_score_for_day = 0
                    for todo in filtered_todoitem:
                        key = todo.key()
                        editlink = """<a href="/edit?key=%(key)s">Edit</a>""" % {'key':key}
                        self.response.out.write("""
                        <li><b>%s</b>  <i>%s</i>/<i>%s</i>  - %s </br>""" % (todo.description,
                            todo.score, todo.rating, editlink))
                        total_rating_for_day += todo.rating
                        total_score_for_day += todo.score

                    self.response.out.write("</ul>")
                    score = (100.0 * total_score_for_day) / total_rating_for_day
                    todolist.dayscore = score
                    todolist.put()

                    todolist_queryobj = db.Query(TodoList)
                    filtered_todolist = todolist_queryobj.filter('user =',username)
                    discipline_score = 0.0
                    number_of_entrys = 0
                    for todolist_entry in filtered_todolist:
                        discipline_score += todolist_entry.dayscore
                        number_of_entrys += 1

                    self.response.out.write("<br>")
                    self.response.out.write("<h3>Score for the day - %0.2f %% </h3>" % str(score))
                    self.response.out.write("<br>")
                    self.response.out.write("<h3>Discipline Score- %0.2f %% </h3>" % str(discipline_score/number_of_entrys))
                    self.response.out.write("<br>")
                    self.response.out.write("""</br>""")

            self.response.out.write("""Check the <a href="/archives">archives</a>?""")
            self.response.out.write("""</br>""")
            self.response.out.write("""</br>""")
            self.response.out.write("<a href='%s'>Logout?</a>" % users.create_logout_url("/"))
            self.response.out.write("""</br>""")
            self.response.out.write("<a href='http://3.discipline-score.appspot.com'>Older Version</a>")
            self.response.out.write("</html>")
        else:
            self.redirect(users.create_login_url(self.request.uri))

class EditEntry(webapp.RequestHandler):
    def get(self):
        item_key = self.request.get('key')
        item = db.get(item_key)
        self.response.out.write("<html>")
        self.response.out.write("<title>Discipline Score</title>")
        form_contents = """
        <form action="/update" method="post"/>
        <div>Description</br><textarea name="description"
        label="description" rows="3" cols="60">%(description)s</textarea></div>
        <div>Rating</br><textarea name="rating" label="rating" rows="1" cols="10">%(rating)s</textarea></div>
        <div>Score</br><textarea name="score" label="score" rows="1" cols="10">%(score)s</textarea></div>
        <div><input type="submit" value="submit"></div>
        </form>
        """
        form_contents %= {'description':item.description,'rating':item.rating,'score':item.score}
        self.response.out.write(form_contents)
        self.response.out.write('</html>')

class NewEntry(webapp.RequestHandler):

    def get(self):
        username = users.get_current_user()
        if username:
            self.response.out.write("<html>")
            self.response.out.write("<title>discipline score</title>")
            self.response.out.write("""
            <form action="/new" method="post"/>
            <div>Description</br><textarea name="description" label="description" rows="3" cols="60">Task Description</textarea></div>
            <div>Rating</br><textarea name="rating" label="rating" rows="1" cols="10"></textarea></div>
            <div>Score</br><textarea name="score" label="score" rows="1" cols="10"></textarea></div>
            <div><input type="submit" value="submit"></div>
            </form>
            """)
            self.response.out.write("</html>")
        else:
            self.redirect(users.create_login_url(self.request.uri))

    def post(self):
        username = users.get_current_user()
        if username:
            description = self.request.get('description',default_value='')
            rating = int(self.request.get('rating',default_value='10'))
            score = int(self.request.get('score',default_value='0'))

            timezoneinfo_obj = db.Query(TimezoneInfo)
            filtered_timezoneinfo = timezoneinfo_obj.filter('user =', username)
            if not filtered_timezoneinfo.fetch(limit=1):
                self.redirect('/settimezone')

            usertimezone = filtered_timezoneinfo.get()
            user_tzinfo = timezone(usertimezone.timezoneinfo)

            #Add a todoitem for today
            today = datetime.datetime.now(user_tzinfo).strftime('%d%m%Y')

            todolist_queryobj = db.Query(TodoList)
            filtered_todolist = todolist_queryobj.filter('daykey =', today).filter('user =', username)
            if not filtered_todolist.fetch(limit=1):
                todolist = TodoList(daykey=today, user=username)
                todolist.put()
            else:
                todolist = filtered_todolist.get()
            todoitem = TodoItem(user=username, belongs_to=todolist, description=description, rating=rating, score=score)
            todoitem.put()
            self.redirect('/')
        else:
            self.redirect(users.create_login_url(self.request.uri))

class Archives(webapp.RequestHandler):
    def get(self):
        self.response.out.write("<html>")
        self.response.out.write("<title>discipline-score archives</title>")
        username = users.get_current_user()
        if username:
            todolist_queryobj = db.Query(TodoList)
            filtered_todolist = todolist_queryobj.filter('user =', username)
            if not filtered_todolist.fetch(limit=1):
                self.response.out.write("""</br>No Todos for you yet.</br>""")
                self.response.out.write("""Why not create one <a href="/new">now</a>?""")
            else:
                self.response.out.write("<ul>")
                for todolist in filtered_todolist:
                    todolist.daykey
                    todolist.dayscore
                    day = todolist.daykey[:2] + '-' + todolist.daykey[2:4] + '-' +todolist.daykey[4:]

                    daylink = """<a href="/?day=%(daykey)s">%(day)s</a>""" % {'daykey':todolist.daykey, 'day':day}
                    self.response.out.write("""
                    <li>%s - <b>%s</b> </br>""" % (daylink, todolist.dayscore))

                self.response.out.write("</ul>")

            self.response.out.write("""Go to <a href="/">Main</a>?""")
            self.response.out.write("""</br>""")
            self.response.out.write("<a href='%s'>Logout?</a>" % users.create_logout_url("/"))
            self.response.out.write("""</br>""")
            self.response.out.write("<a href='http://3.discipline-score.appspot.com'>Older Version</a>")
            self.response.out.write("</html>")
        else:
            self.redirect(users.create_login_url(self.request.uri))

application = webapp.WSGIApplication([
    ('/', MainPage),
    ('/edit',EditEntry),
    ('/settimezone',SetTimeZone),
    ('/new',NewEntry),
    ('/archives', Archives),
    ('/update',UpdateTodo)],debug=True)

def main():
    run_wsgi_app(application)

if __name__ == '__main__':
  main()
