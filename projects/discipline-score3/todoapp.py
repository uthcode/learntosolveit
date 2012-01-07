import cgi
import datetime
import random
import urllib

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
            self.response.out.write("""
            <html>
            <body>
            """)
            username = user
            Query_TodoList = db.Query(TodoList)
            Query_Filtered = Query_TodoList.filter('daykey =', today).filter('user =',username)
            if not Query_Filtered.fetch(limit=1):
                todolist = TodoList(daykey=today, user=username)
                todolist.put()
                self.response.out.write("""</br>No todos for you yet</br>""")
            else:
                # there should be only one list for a user for a day.
                todolist = Query_Filtered.get()
                todoitem_query = db.Query(TodoItem)
                todoitem = todoitem_query.filter('belongs_to =', todolist).filter('user =',username)
                for todo in todoitem:
                    self.response.out.write("""Description: %s\nRating: %s\nScore: %s""" % (todo.description, todo.rating,
                                todo.score))

            self.response.out.write("""
            <form action="/update" method="post"/>
            <div><textarea name="description" rows="3" cols="60></textarea></div>
            <div><textarea name="rating" rows="1" cols="10></textarea></div>
            <div><textarea name="score" rows="1" cols="10></textarea></div>
            <div><input type="submit" value="Update"></div>
            </form>
            """)
            user_rating = random.randint(1,10)
            user_score = random.randint(1,10)
            todoitem = TodoItem(user=username,belongs_to=todolist,description='something',rating=user_rating,score=user_score)
            todoitem.put()
            self.response.out.write('todo item written')
        else:
            self.redirect(users.create_login_url(self.request.uri))

class UpdateTodo(webapp.RequestHandler):
    def get(self):
        username = users.get_current_user()
        if username:
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
                self.redirect('/')
        else:
            self.redirect(users.create_login_url(self.request.uri))
    def post(self):
        username = users.get_current_user()
        if username:
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
                self.redirect('/')
        else:
            self.redirect(users.create_login_url(self.request.uri))


class MainPage(webapp.RequestHandler):
    def get(self):
        self.response.out.write("<html>")
        username = users.get_current_user()
        if username:
            today = datetime.datetime.today().strftime('%d%m%Y')
            todolist_queryobj = db.Query(TodoList)
            filtered_todolist = todolist_queryobj.filter('daykey =', today).filter('user =', username)
            if not filtered_todolist.fetch(limit=1):
                todolist = TodoList(daykey=today, user=username)
                todolist.put()
                self.response.out.write("""</br>No todos for you yet.</br>""")
                self.response.out.write("""Why not create one <a href="/new">now</a>?""")
            else:
                # there should be only one list for a user for a day.
                todolist = filtered_todolist.get()
                todoitem_queryobj = db.Query(TodoItem)
                filtered_todoitem = todoitem_queryobj.filter('belongs_to =',
                        todolist).filter('user =', username)
                self.response.out.write("<ul>")
                for todo in filtered_todoitem:
                    key = todo.key()
                    editlink = """<a href="/edit?key=%(key)s">Edit</a>""" % {'key':key}
                    self.response.out.write("""
                    <li><b>%s</b>  <i>%s</i>  <i>%s</i>  - %s </br>""" % (todo.description,
                        todo.rating, todo.score, editlink))

                self.response.out.write("</ul>")
            self.response.out.write("<br>")
            self.response.out.write("""Add a new todo <a href="/new">now</a>?""")
            self.response.out.write("</html>")
        else:
            self.redirect(users.create_login_url(self.request.uri))

class EditEntry(webapp.RequestHandler):
    def get(self):
        item_key = self.request.get('key')
        item = db.get(item_key)
        self.response.out.write("<html>")
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
            rating = int(self.request.get('rating',default_value=10))
            score = int(self.request.get('score',default_value=10))

            #Add a todoitem for today
            today = datetime.datetime.today().strftime('%d%m%Y')
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

application = webapp.WSGIApplication([
    ('/', MainPage),
    ('/edit',EditEntry),
    ('/new',NewEntry),
    ('/', CreateTodo),
    ('/update',UpdateTodo)],debug=True)

def main():
    run_wsgi_app(application)

if __name__ == '__main__':
  main()
