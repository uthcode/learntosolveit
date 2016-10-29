import smtplib

from email.MIMEMultipart import MIMEMultipart
from email.MIMEBase import MIMEBase
from email.MIMEText import MIMEText
from email import Encoders
import os
import time

me = 'Name <email@gmail.com>'

username = ''
password = 'password'
textfile = 'message.txt'
attachment = 'picture.png'

def send_email(name, to_email):
	you = to_email
	msg = MIMEMultipart()

	msg['From'] = me
	msg['To'] = you
	msg['Subject'] = 'Subject'

	fp = open(textfile, 'rb')
	contents = fp.read()
	contents = contents.format(friend=name)
	msg.attach(MIMEText(contents))
	fp.close()

	email_attachment = MIMEBase('application','octet-stream')
	email_attachment.set_payload(open(attachment, 'rb').read())
	Encoders.encode_base64(email_attachment)
	email_attachment.add_header('Content-Disposition', 'attachment; filename="%s"' % os.path.basename(attachment))

	msg.attach(email_attachment)

	server = smtplib.SMTP('smtp.gmail.com:587')
	server.ehlo()
	server.starttls()
	server.ehlo()
	server.login(username, password)
	server.sendmail(me, [you], msg.as_string())
	server.close()

if __name__ == '__main__':
	name = "recipient name"
	email = "recipient email"
	send_email(name, email)
