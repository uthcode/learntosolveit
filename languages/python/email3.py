"""
Sending gmail with attachment.
"""
import smtplib

from email.MIMEMultipart import MIMEMultipart
from email.MIMEBase import MIMEBase
from email.MIMEText import MIMEText
from email import Encoders

me = 'Senthil Kumaran <orsenthil@gmail.com>'
you = 'senthil@uthcode.com'

username = 'orsenthil'
password = 'something'
textfile = 'message.txt'
attachment = 'something.pdf'

msg = MIMEMultipart()

msg['From'] = me
msg['To'] = you
msg['Subject'] = 'The contents of %s' % textfile

fp = open(textfile, 'rb')
msg.attach(MIMEText(fp.read()))
fp.close()

email_attachment = MIMEBase('application','octet-stream')
email_attachment.set_payload(open(attachment, 'rb').read())
Encoders.encode_base64(email_attachment)
email_attachment.add_header('Content-Disposition', 'attachment; filename="%s"' % os.path.basename(attach))

msg.attach(email_attachment)


server = smptlib.SMTP('smtp.gmail.com:587')
server.ehlo()
server.starttls()
server.ehlo()
server.login(username, password)
server.sendmail(me, [you], msg.as_string())
server.close()
