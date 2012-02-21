import cgi
import datetime
import logging
import os
import random
import string

from google.appengine.ext import db
from google.appengine.api import users
from google.appengine.ext import webapp
from google.appengine.ext.webapp.util import run_wsgi_app
from google.appengine.api import images
from google.appengine.ext.webapp import template
from google.appengine.api import mail

logging.getLogger().setLevel(logging.DEBUG)

class Resume(db.Model):
    user = db.UserProperty()
    emailid = db.EmailProperty()
    resumepdf = db.BlobProperty()
    resumedoc = db.BlobProperty()
    stackoverflow = db.LinkProperty()
    linkedin = db.LinkProperty()

class MainHandler(webapp.RequestHandler):
    def get(self):
        """resumator application"""
        username = users.get_current_user()
        if username:
            values = {'username':username}
            template_loc = os.path.join(os.path.dirname(__file__),'templates',
                    'index.html')
            self.response.out.write(template.render(template_loc, values))
        else:
            self.redirect(users.create_login_url(self.request.uri))

    def post(self):
        """send your resume to email id provided"""
        username = users.get_current_user()
        emailid = username.email()
        resume_obj = Resume.get_by_key_name(emailid)
        employer_id = self.request.get('emailid')
        employer_domain = employer_id.split('@')[-1]
        employer_name = employer_domain.split('.')[0]

        if resume_obj.stackoverflow:
            stackoverflow = resume_obj.stackoverflow
        else:
            stackoverflow = "http://www.stackoverflow.com"

        if resume_obj.linkedin:
            linkedin = resume_obj.linkedin
        else:
            linkedin = "http://www.linkedin.com"

        values_dict = {"employer_name":employer_name,
                        "stackoverflow": stackoverflow,
                        "linkedin": linkedin
                        }
        mail.send_mail(sender=emailid,
                to=employer_id,
                reply_to=emailid,
                subject='Senior/Lead Developer - Python, C++, Architecture',
                body="""
Hello %(employer_name)s Team,

I am excited to see this job opening for a Senior developer. I have good
experience in designing systems using Python and twisted and have special
interest in Networking protocols. I am Python Core developer and maintainer of
urllib and related modules.

I would like to work for an organization which has strong engineering focus and
hacker culture such as %(employer_name)s. Please consider my resume for this job
opening.

Here is my resume for the opening you have at your company.

Additionally, here is %(stackoverflow)s link which gives a certain details on my
technical aptitude and %(linkedin)s profile for my professional connections.

Thanks,
Senthil

""" % (values_dict),
                attachments=[('Senthil_Kumaran.pdf', resume_obj.resumepdf),
                             ('Senthil_Kumaran.doc',resume_obj.resumedoc)
                             ])
        self.redirect('/sent')


class CreatePage(webapp.RequestHandler):
    def get(self):
        """create your resume"""
        username = users.get_current_user()
        if username:
            values = {'username':username}
            template_loc = os.path.join(os.path.dirname(__file__),'templates',
                    'create.html')
            self.response.out.write(template.render(template_loc, values))
        else:
            self.redirect(users.create_login_url(self.request.uri))

    def post(self):
        """upload resume to your database"""
        username = users.get_current_user()
        if username:
            emailid = username.email()
            resume = Resume.get_by_key_name(emailid)
            if not resume:
                resume = Resume(key_name = emailid, user = username, emailid = emailid)
            resumepdf = self.request.get("resumepdf")
            resumedoc = self.request.get("resumedoc")
            stackoverflow = self.request.get("stackoverflow")
            linkedin = self.request.get("linkedin")
            if resumepdf: resume.resumepdf = db.Blob(resumepdf)
            if resumedoc: resume.resumedoc = db.Blob(resumedoc)
            if stackoverflow: resume.stackoverflow = stackoverflow
            if linkedin: resume.linkedin = linkedin
            resume.put()
            self.redirect('/success')
        else:
            self.redirect(users.create_login_url(self.request.uri))

class SuccessPage(webapp.RequestHandler):
    def get(self):
        """resume update successful"""
        username = users.get_current_user()
        if username:
            values = {'username':username}
            template_loc = os.path.join(os.path.dirname(__file__),'templates',
                    'success.html')
            self.response.out.write(template.render(template_loc, values))
        else:
            self.redirect(users.create_login_url(self.request.uri))

class SentHandler(webapp.RequestHandler):
    def get(self):
        """resume update successful"""
        username = users.get_current_user()
        if username:
            values = {'username':username}
            template_loc = os.path.join(os.path.dirname(__file__),'templates',
                    'sent.html')
            self.response.out.write(template.render(template_loc, values))
        else:
            self.redirect(users.create_login_url(self.request.uri))

application = webapp.WSGIApplication([
    ('/', MainHandler),
    ('/create', CreatePage),
    ('/success', SuccessPage),
    ('/sent', SentHandler),
], debug=True)

def main():
    logging.getLogger().setLevel(logging.DEBUG)
    run_wsgi_app(application)

if __name__ == '__main__':
    main()
