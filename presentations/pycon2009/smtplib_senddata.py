import smtplib
import email.utils
from email.mime.text import MIMEText

# Create the message

msg = MIMEText('Well, it just seemed wrong to cheat on an ethics test.  --\
               Calvin')
msg['To'] = email.utils.formataddr(('Recipient','recipient@example.com'))
msg['From'] = email.utils.formataddr(('Author','author@example.com'))
msg['Subject'] = 'I am home, Hobbes.'

server = smtplib.SMTP('127.0.0.1', 1025)
server.set_debuglevel(True) # Logs the communication with the server

try:
    server.sendmail('author@example.com',
                    ['recipient@example.com'],msg.as_string())
finally:
    server.quit()

