#!/usr/bin/env python

import webapp2
import cgi
import re

form = """
<html>
<form method="post" action="/unit2">
<textarea name="text">%s</textarea>
<input type="submit">
</form>
</html>
"""

form2 = """
<html>
<h2>User Signup Page</h2>
<form method="post" action="/unit2/signup">
<label>
Name:
<input type="text" name="username" value="%(username)s">
<div style="color: red">%(username_error)s</div>
</label>
<label>
Password:
<input type="password" name="password" value="">
<div style="color: red">%(password_error)s</div>
</label>
<label>
Verify Password:
<input type="password" name="verify" value="">
<div style="color: red">%(verify_password_error)s</div>
</label>
<label>
Email:
<input type="text" name="email" value="%(email)s">
<div style="color: red">%(email_error)s</div>
</label>
<input type="submit">
</form>

</html>
"""

def verify_username(username):
    USER_RE = re.compile(r"^[a-zA-Z0-9_-]{3,20}$")
    return USER_RE.match(username)

def verify_password(password):
    USER_PASS = re.compile(r"^.{3,20}$")
    return USER_PASS.match(password)

def verify_email(email):
    USER_EMAIL = re.compile(r"^[\S]+@[\S]+\.[\S]+$")
    return USER_EMAIL.match(email)

class MainHandler(webapp2.RequestHandler):

    def get(self):
        self.response.out.write('Hello world!')


class RotHandler(webapp2.RequestHandler):

    def get(self, content=""):
        newform = form % (content,)
        self.response.out.write(newform)

    def post(self):
        text = self.request.get('text')
        text = text.encode('rot13')
        text = cgi.escape(text)
        newform = form % (text,)
        self.response.out.write(newform)


class UserHandler(webapp2.RequestHandler):

    def write_form(self, email_error="",
                         email="",
                         verify_password_error="",
                         password_error="",
                         username_error="",
                         username=""):

        form_contents = {'email_error': email_error,
                         'email': email,
                         'verify_password_error': verify_password_error,
                         'password_error': password_error,
                         'username_error': username_error,
                         'username': username
                        }
        self.response.out.write(form2 % form_contents)

    def get(self):
        self.write_form(email_error="", email="",
                   verify_password_error="", password_error="",
                   username_error="", username="")


    def post(self):
        username = self.request.get('username')
        username = cgi.escape(username)
        password = self.request.get('password')
        verify = self.request.get('verify')
        email = self.request.get('email')
        email = cgi.escape(email)

        if (verify_username(username) and verify_password(password) and \
            verify_password(verify) and  password == verify and \
            (verify_email(email) or email == "")):

            redirect_url = "/welcome?q=" + username
            self.redirect(redirect_url)
        else:
            if not verify_username(username):
                username_error = "Invalid Username"
            else:
                username_error = ""
            if not verify_password(password):
                password_error = "Invalid Password"
            else:
                password_error = ""
            if not password == verify:
                verify_password_error = "Password verification Error"
            else:
                verify_password_error = ""
            if email:
                if verify_email(email):
                    email_error = "Invalid Email"
            else:
                email_error = ""

            self.write_form(email_error=email_error,
                            email=email,
                            verify_password_error=verify_password_error,
                            password_error=password_error,
                            username_error=username_error,
                            username=username)

class WelcomeHandler(webapp2.RequestHandler):

    def get(self):
        username = self.request.get("q")
        output = "Welcome, %s" % username
        self.response.out.write(output)

app = webapp2.WSGIApplication([('/', MainHandler),
                               ('/unit2', RotHandler),
                               ('/unit2/signup', UserHandler),
                               ('/welcome', WelcomeHandler),],
                              debug=True)
