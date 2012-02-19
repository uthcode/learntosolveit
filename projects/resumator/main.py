import cgi
import datetime
import logging
import os
import random
import string

from google.appengine.ext import db
from google.appengine.ext import webapp
from google.appengine.ext.webapp.util import run_wsgi_app
from google.appengine.api import images
from google.appengine.ext.webapp import template
from google.appengine.api import mail

logging.getLogger().setLevel(logging.DEBUG)

class Resume(db.Model):
    user = db.UserProperty()
    pdfformat = db.BlobProperty()
    docformat = db.BlobProperty()
    stackoverflow = db.LinkProperty()
    linkedin = db.LinkProperty()

class MainHandler(webapp.RequestHandler):
    def get(self):
        """resumator application"""
        values = { }
        template_loc = os.path.join(os.path.dirname(__file__),'templates',
                'index.html')
        self.response.out.write(template.render(template_loc, values))

class CreatePage(webapp.RequestHandler):
    def get(self):
        """create your resume"""
        values = { }
        template_loc = os.path.join(os.path.dirname(__file__),'templates',
                'create.html')
        self.response.out.write(template.render(template_loc, values))

    def post(self):
        """upload resume to your database"""
        resume = Resume(user=username)
        resumepdf = self.request.get("resumepdf")
        resumedoc = self.request.get("resumedoc")
        stackoverflow = self.request.get("stackoverflow")
        linkedin = self.request.get("linkedin")
        resume.resumepdf = db.Blob(resumepdf)
        resume.resumedoc = db.Blob(resumedoc)
        resume.stackoverflow = stackoverflow
        resume.linkedin = linkedin
        resume.put()
        self.redirect('/')


class SendHandler(webapp.RequestHandler):
    def get(self,ecard):
        values = {'ecard': ecard}
        template_loc = os.path.join(os.path.dirname(__file__),'templates',
                'selected.html')
        self.response.out.write(template.render(template_loc, values))

class MailHandler(webapp.RequestHandler):
    def post(self):
        ecard = self.request.get('ecard')
        chosencard = Greeting.get_by_key_name(ecard)
        friendemail = self.request.get('friendemail')
        friend = self.request.get('friend')
        me = self.request.get('you')
        myemail = self.request.get('youremail')
        mail.send_mail(sender='shalgreetings@shalgreetings.appspotmail.com',
                to=friendemail,
                reply_to=myemail,
                subject='Hello %s!' % friend,
                body="""
Hello %s,

I have this nice card for you. Hope you like it.

Thanks,
%s

Card from http://www.shalgreetings.com
""" % (friend,me),
                attachments=[('greetings.jpg', chosencard.cardimage)])
        self.redirect('/')


application = webapp.WSGIApplication([
    ('/', MainHandler),
    ('/create', CreatePage),
    ('/export', EditedHandler),
    ('/ecard/(.*)', EcardHandler),
    ('/sendit/(.*)', SendHandler),
    ('/mail', MailHandler),
    ('/submit', Guestbook),
    ('/cards/(.*)',ImageHandler)
], debug=True)

def main():
    logging.getLogger().setLevel(logging.DEBUG)
    run_wsgi_app(application)

if __name__ == '__main__':
    main()
