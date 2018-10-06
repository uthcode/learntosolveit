"""
Python3 script to send email via gmail.

Pre-requisite: https://www.google.com/settings/security/lesssecureapps
"""
import os
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

_DEFAULT_FROM_ADDRESS = ""
_DEFAULT_FROM_PASSWORD = ""
_DEFAULT_TO_ADDRESS = ""


FROM_ADDRESS = os.environ.get("FROM_ADDRESS", _DEFAULT_FROM_ADDRESS)
FROM_PASSWORD = os.environ.get("FROM_PASSWORD", _DEFAULT_FROM_PASSWORD)
TO_ADDRESS = os.environ.get("TO_ADDRESS", _DEFAULT_TO_ADDRESS)
MAIL_SERVER = "smtp.gmail.com"
MAIL_PORT = 587


def create_message(subject="", body="") -> MIMEMultipart:
    msg = MIMEMultipart()
    msg["From"] = FROM_ADDRESS
    msg["To"] = TO_ADDRESS
    msg["Subject"] = subject
    msg.attach(MIMEText(body, 'plain'))
    return msg


def send_mail(msg: MIMEMultipart):
    server = smtplib.SMTP(MAIL_SERVER, MAIL_PORT)
    server.ehlo()
    server.starttls()
    server.login(FROM_ADDRESS, FROM_PASSWORD)
    text = msg.as_string()
    server.sendmail(FROM_ADDRESS, [TO_ADDRESS], text)
    server.quit()


SUBJECT = "Game"

MESSAGE = """
Hello There!

Let's play a game.

Cheers!
"""

if __name__ == '__main__':
    subject = SUBJECT
    body = MESSAGE
    msg = create_message(subject, body)
    send_mail(msg)
