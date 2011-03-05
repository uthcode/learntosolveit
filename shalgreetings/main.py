import cgi
import datetime
import logging
import os

from google.appengine.ext import db
from google.appengine.ext import webapp
from google.appengine.ext.webapp.util import run_wsgi_app
from google.appengine.api import images
from google.appengine.ext.webapp import template
from google.appengine.api import mail

logging.getLogger().setLevel(logging.DEBUG)


class Greeting(db.Model):
    cardid = db.StringProperty()
    cardimage = db.BlobProperty()

class MainHandler(webapp.RequestHandler):
    def get(self):
        """Get the cards and display it."""
        # We are not using any template features at the moment.
        values = { }

        template_loc = os.path.join(os.path.dirname(__file__),'templates',
                'index.html')

        self.response.out.write(template.render(template_loc, values))

class EditedHandler(webapp.RequestHandler):
    def post(self):
        logging.debug("Got to the Edited Handler")
        greeting = Greeting(key_name="ecard")
        greeting.cardid = "ecard"
        cardimage = self.request.get("imgdata")
        greeting.cardimage = db.Blob(cardimage)
        greeting.put()
        logging.debug("Posted the Card Back")
        self.redirect('/sendit')

class EcardHandler(webapp.RequestHandler):
    def get(self):
        logging.debug("Got to the Ecard Handler")
        chosencard = Greeting.get_by_key_name('ecard')
        if chosencard and chosencard.cardimage:
            self.response.headers['Content-Type'] = 'image/jpeg'
            self.response.out.write(chosencard.cardimage)

class SendHandler(webapp.RequestHandler):
    def get(self):
        values = { }
        template_loc = os.path.join(os.path.dirname(__file__),'templates',
                'selected.html')
        self.response.out.write(template.render(template_loc, values))

class MailHandler(webapp.RequestHandler):
    def post(self):
        chosencard = Greeting.get_by_key_name('ecard')
        mail.send_mail(sender='orsenthil@gmail.com',
                to=self.request.get('friendemail'),
                subject='A greeting card for you',
                body="""
                Hi %s,\nA friend has sent the following greetings, \
                        from www.shalgreetings.com """ % (self.request.get('friendname')),
                attachments=[('greetings.jpg', chosencard.cardimage)])
        self.redirect('/')

class UploadPage(webapp.RequestHandler):
    def get(self):
        self.response.out.write("""
              <form action="/submit" enctype="multipart/form-data" method="post">
                <div><label>Message:</label></div>
                <div><textarea name="cardid" cols="60"></textarea></div>
                <div><label>Card:</label></div>
                <div><input type="file" name="cardimage"/></div>
                <div><input type="submit" value="Submit"></div>
              </form>
            </body>
          </html>""")


class ImageHandler(webapp.RequestHandler):

    def get(self, imageid):
        result = db.GqlQuery("SELECT * FROM Greeting WHERE cardid = :1 LIMIT 1", imageid).fetch(1)
        chosencard = result[0]
        if chosencard and chosencard.cardimage:
            self.response.headers['Content-Type'] = 'image/jpeg'
            self.response.out.write(chosencard.cardimage)


class Guestbook(webapp.RequestHandler):
    def post(self):
        greeting = Greeting()
        greeting.cardid = self.request.get("cardid")
        cardimage = self.request.get("cardimage")
        greeting.cardimage = db.Blob(cardimage)
        greeting.put()
        self.redirect('/')


application = webapp.WSGIApplication([
    ('/', MainHandler),
    ('/export', EditedHandler),
    ('/ecard', EcardHandler),
    ('/sendit', SendHandler),
    ('/mail', MailHandler),
    ('/upload', UploadPage),
    ('/submit', Guestbook),
    ('/cards/(.*)',ImageHandler)
], debug=True)


def main():
    logging.getLogger().setLevel(logging.DEBUG)
    run_wsgi_app(application)


if __name__ == '__main__':
    main()
