import datetime
import os

import pytz
from pytz import timezone
import gviz_api

from google.appengine.ext import db
from google.appengine.api import users
from google.appengine.ext import webapp
from google.appengine.ext.webapp.util import run_wsgi_app
from google.appengine.ext.webapp import template

# register custom filters
template.register_template_library('customfilters')

class TimezoneInfo(db.Model):
    timezoneinfo = db.StringProperty(default='')
    user = db.UserProperty(required=True)

class TodoList(db.Model):
    daykey = db.StringProperty(required=True)
    user = db.UserProperty(required=True)
    dayscore = db.FloatProperty(default=0.0)
    future_tasks = db.BooleanProperty(default=False)

class TodoItem(db.Model):
    user = db.UserProperty(required=True)
    date = db.DateTimeProperty(auto_now_add=True)
    belongs_to = db.ReferenceProperty(TodoList)
    description = db.StringProperty(multiline=True)
    start_time = db.TimeProperty(required=False)
    end_time = db.TimeProperty(required=False)
    rating = db.IntegerProperty(required=True, default=0)
    score = db.IntegerProperty(default=0)

class SetTimeZone(webapp.RequestHandler):

    def get(self):
        username = users.get_current_user()
        if username:
            path = os.path.join(os.path.dirname(__file__), 'timezone.html')
            self.response.out.write(template.render(path, {}))
        else:
            self.redirect(users.create_login_url(self.request.uri))

    def post(self):
        username = users.get_current_user()
        timezoneinfo = self.request.get('DropDownTimezone',default_value='UTC')
        if username:
            try:
                timezone(timezoneinfo)
            except pytz.UnknownTimeZoneError, e:
                self.response.out.write("<h2>Unknown Timezone</h2>")
                self.response.out.write("</br>")
                self.response.out.write("<h2>Please <a href='/settimezone'>set timezone</a>.</h2>")
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
        # I think, we do not need get here as it is not done.
        pass

    def post(self):
        username = users.get_current_user()
        if username:
            key = self.request.get('key',default_value=None)
            if not key:
                self.response.out.write("You do not have such a todo item")
            else:
                item = db.get(key)
                item.description = self.request.get('description',
                        default_value='default')

                item.rating = int(self.request.get('rating', default_value=10))
                item.score = int(self.request.get('score',default_value=0))
                item.put()
                self.redirect('/')
        else:
            self.redirect(users.create_login_url(self.request.uri))


class MainPage(webapp.RequestHandler):
    def get(self):
        username = users.get_current_user()
        path = os.path.join(os.path.dirname(__file__), 'index.html')
        template_values = {}

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

                datetime_obj = datetime.datetime.strptime(displaydate,"%d-%m-%Y")
                displaydate = datetime_obj.strftime("%a %d %b %Y")

                template_values.update({'displaydate': displaydate})
                todolist_queryobj = db.Query(TodoList)
                filtered_todolist = todolist_queryobj.filter('daykey =', today).filter('user =', username)
                if not filtered_todolist.fetch(limit=1) or filtered_todolist.future_tasks:
                    if filtered_todolist.future_tasks:
                        filtered_todolist.future_tasks = False
                        filtered_todolist.put()
                        new_todolist = filtered_todolist
                    else:
                        # There is no todolist for the day yet.
                        today_todolist = TodoList(daykey=today, user=username)
                        today_todolist.put()
                        new_todolist = today_todolist

                    # At this point pull unfinished from yesterday's
                    yesterday = datetime.datetime.now(user_tzinfo) - datetime.timedelta(1)
                    yesterday = yesterday.strftime('%d%m%Y')

                    todolist_queryobj = db.Query(TodoList)
                    yesterday_todolist = todolist_queryobj.filter('daykey =', yesterday).filter('user =', username)
                    yesterday_todolist = yesterday_todolist.get()

                    todoitem_queryobj = db.Query(TodoItem)
                    filtered_todoitem = todoitem_queryobj.filter('belongs_to =',
                            yesterday_todolist).filter('user =', username)

                    for todo in filtered_todoitem:
                        # incomplete todos from yesterday.
                        if todo.score < todo.rating:
                            todoitem = TodoItem(user=username,
                                                belongs_to=new_todolist,
                                                description=todo.description,
                                                rating=todo.rating,
                                                score=todo.score)
                            todoitem.put()
                        self.response.out.write("Yesterday's unfinished tasks added.")
                        self.redirect('/')
                else:
                    # there should be only one list for a user for a day.
                    todolist = filtered_todolist.get()

                    todoitem_queryobj = db.Query(TodoItem)
                    filtered_todoitem = todoitem_queryobj.filter('belongs_to =',
                            todolist).filter('user =', username)
                    if filtered_todoitem:
                        total_rating_for_day = 0
                        total_score_for_day = 0
                        for todo in filtered_todoitem:
                            total_rating_for_day += todo.rating
                            total_score_for_day += todo.score

                        if total_rating_for_day:
                            score = (100.0 * total_score_for_day) / total_rating_for_day
                        else:
                            score = 0.0
                        todolist.dayscore = score
                        todolist.put()

                        todolist_queryobj = db.Query(TodoList)
                        filtered_todolist = todolist_queryobj.filter('user =',username)
                        discipline_score = 0.0
                        number_of_entrys = 0
                        for todolist_entry in filtered_todolist:
                            discipline_score += todolist_entry.dayscore
                            number_of_entrys += 1

                        score = "%0.2f" % score
                        total_score = "%0.2f" % (discipline_score/number_of_entrys)
                        template_values.update({'score':score, 'total_score':total_score})
                        template_values.update({'filtered_todoitem':filtered_todoitem})

            logout_url = users.create_logout_url('/')
            template_values.update({'logout':logout_url})
            self.response.out.write(template.render(path, template_values))
        else:
            self.redirect(users.create_login_url(self.request.uri))

class EditEntry(webapp.RequestHandler):
    def get(self):
        item_key = self.request.get('key')
        item = db.get(item_key)
        form_contents = {'description':item.description,
                'rating':item.rating,
                'score':item.score,
                'key': item_key}
        path = os.path.join(os.path.dirname(__file__), 'edit.html')
        self.response.out.write(template.render(path, form_contents))

class NewEntry(webapp.RequestHandler):

    def get(self):
        username = users.get_current_user()
        if username:
            path = os.path.join(os.path.dirname(__file__), 'new.html')
            self.response.out.write(template.render(path, {}))
        else:
            self.redirect(users.create_login_url(self.request.uri))

    def post(self):
        username = users.get_current_user()
        if username:
            description = self.request.get('description',default_value='')
            starttime = self.request.get('starttime',default_value='00:00')
            endtime = self.request.get('endtime',default_value='00:00')
            rating = int(self.request.get('rating',default_value='10'))
            score = int(self.request.get('score',default_value='0'))

            timezoneinfo_obj = db.Query(TimezoneInfo)
            filtered_timezoneinfo = timezoneinfo_obj.filter('user =', username)
            if not filtered_timezoneinfo.fetch(limit=1):
                self.redirect('/settimezone')

            usertimezone = filtered_timezoneinfo.get()
            user_tzinfo = timezone(usertimezone.timezoneinfo)

            today = datetime.datetime.now(user_tzinfo).strftime('%d%m%Y')

            starttime_hour, starttime_min = map(int, starttime.split(':'))
            endtime_hour, endtime_min = map(int, endtime.split(':'))

            starttime = datetime.time(starttime_hour, starttime_min, tzinfo=user_tzinfo)
            endtime = datetime.time(endtime_hour, endtime_min, tzinfo=user_tzinfo)


            todolist_queryobj = db.Query(TodoList)
            filtered_todolist = todolist_queryobj.filter('daykey =', today).filter('user =', username)
            if not filtered_todolist.fetch(limit=1):
                todolist = TodoList(daykey=today, user=username)
                todolist.put()
            else:
                todolist = filtered_todolist.get()
            todoitem = TodoItem(user=username, belongs_to=todolist, description=description, start_time = starttime, end_time = endtime, rating=rating, score=score)
            todoitem.put()
            self.redirect('/')
        else:
            self.redirect(users.create_login_url(self.request.uri))

class FutureEntry(webapp.RequestHandler):

    def get(self):
        username = users.get_current_user()
        if username:
            path = os.path.join(os.path.dirname(__file__), 'future.html')
            self.response.out.write(template.render(path, {}))
        else:
            self.redirect(users.create_login_url(self.request.uri))

    def post(self):
        username = users.get_current_user()
        if username:
            future_date_value = self.request.get('future', default_value='')
            description = self.request.get('description',default_value='')
            starttime = self.request.get('starttime',default_value='00:00')
            endtime = self.request.get('endtime',default_value='00:00')
            rating = int(self.request.get('rating',default_value='10'))
            score = int(self.request.get('score',default_value='0'))

            timezoneinfo_obj = db.Query(TimezoneInfo)
            filtered_timezoneinfo = timezoneinfo_obj.filter('user =', username)
            if not filtered_timezoneinfo.fetch(limit=1):
                self.redirect('/settimezone')

            usertimezone = filtered_timezoneinfo.get()
            user_tzinfo = timezone(usertimezone.timezoneinfo)

            today = datetime.datetime.now(user_tzinfo).strftime('%d%m%Y')


            if future_date_value:
                future_date = datetime.datetime.strptime(future_date_value,'%m/%d/%Y')
                future_date = future_date.strftime('%d%m%Y')

            starttime_hour, starttime_min = map(int, starttime.split(':'))
            endtime_hour, endtime_min = map(int, endtime.split(':'))

            starttime = datetime.time(starttime_hour, starttime_min, tzinfo=user_tzinfo)
            endtime = datetime.time(endtime_hour, endtime_min, tzinfo=user_tzinfo)

            todolist_queryobj = db.Query(TodoList)
            filtered_todolist = todolist_queryobj.filter('daykey =', future_date).filter('user =', username)
            if not filtered_todolist.fetch(limit=1):
                todolist = TodoList(daykey=future_date, future_tasks = True, user=username)
                todolist.put()
            else:
                todolist = filtered_todolist.get()
            todoitem = TodoItem(user=username, belongs_to=todolist, description=description, start_time=starttime, end_time=endtime, rating=rating, score=score)
            todoitem.put()
            self.redirect('/')
        else:
            self.redirect(users.create_login_url(self.request.uri))

class Archives(webapp.RequestHandler):
    def get(self):
        username = users.get_current_user()
        path = os.path.join(os.path.dirname(__file__), 'archives.html')
        if username:
            todolist_queryobj = db.Query(TodoList)
            filtered_todolist = todolist_queryobj.filter('user =', username)
            if not filtered_todolist.fetch(limit=1):
                no_todos = True
                filtered_todolist = None
            else:
                no_todos = False
                filtered_todolist = filtered_todolist

            logout = users.create_logout_url("/")
            archive_contents = { 'no_todos': no_todos,
                    'filtered_todolist' :filtered_todolist,
                    'logout':logout}
            self.response.out.write(template.render(path, archive_contents))
        else:
            self.redirect(users.create_login_url(self.request.uri))

class Graph(webapp.RequestHandler):
    def get(self):
        username = users.get_current_user()
        path = os.path.join(os.path.dirname(__file__), 'graph.html')
        if username:
            todolist_queryobj = db.Query(TodoList)
            filtered_todolist = todolist_queryobj.filter('user =', username)
            if not filtered_todolist.fetch(limit=1):
                no_todos = True
                filtered_todolist = None
            else:
                no_todos = False
                filtered_todolist = filtered_todolist

            logout = users.create_logout_url("/")
            description = {"day": ("string","Day"),
                           "score": ("number", "Day Scores"),
                           "disciplinescore": ("number", "Discipline Score")
                           }
            data = []
            data_table = gviz_api.DataTable(description)

            num_days = 1.0
            score_so_far = 0.0
            for todolist in filtered_todolist:
                score_so_far += todolist.dayscore
                discipline_score = round(score_so_far/num_days, 2)
                num_days += 1
                item = {"day": todolist.daykey,"score":todolist.dayscore, "disciplinescore": discipline_score}
                data.append(item)

            points = len(data)
            data.sort(key=lambda x:datetime.datetime.strptime(x["day"],"%d%m%Y"))
            data_table.LoadData(data)
            json_data = data_table.ToJSon(columns_order=("day","score","disciplinescore"))
            archive_contents = { 'no_todos': no_todos,
                    'filtered_todolist' :filtered_todolist,
                    'json_data' :json_data,
                    'username': username,
                    'points':points,
                    'disciplinescore': discipline_score,
                    'logout':logout}
            self.response.out.write(template.render(path, archive_contents))
        else:
            self.redirect(users.create_login_url(self.request.uri))

application = webapp.WSGIApplication([
    ('/', MainPage),
    ('/edit',EditEntry),
    ('/settimezone',SetTimeZone),
    ('/new',NewEntry),
    ('/future',FutureEntry),
    ('/archives', Archives),
    ('/graph', Graph),
    ('/update',UpdateTodo)],debug=True)

def main():
    run_wsgi_app(application)

if __name__ == '__main__':
  main()
