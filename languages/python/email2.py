import smtplib
import getpass

fromaddr = 'orsenthil@gmail.com'
toaddrs  = 'senthil@uthcode.com'
msg = 'There was a terrible error that occured and I wanted you to know!'

# Credentials (if needed)
username = 'orsenthil'
password = getpass.getpass()

# The actual mail send
server = smtplib.SMTP('smtp.gmail.com:587')
server.starttls()
server.login(username,password)
server.sendmail(fromaddr, toaddrs, msg)
server.quit()
