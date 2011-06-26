#!/usr/bin/python

#
#
# Simple LiveJournal poster, in order to be used together
# with vim. Should be a quick replacement until ljpy would
# get released finally :)
#
#

import urllib2
import urllib
import rfc822
import sys
import md5
import codecs
import time
import re
import types
import sys
from ConfigParser import ConfigParser

#
# In all cases, we take four arguments:
# pyljpost.py <username> <password> <terminal-encoding> <filename>
#
# If a filename is "-", we'll read from stdin.

if len(sys.argv) != 5:
	sys.stderr.write("Incorrect number of arguments, dying..\n")
	sys.exit(1)

# Now, we can be sure we have 4 arguments precisely.
lj_username = sys.argv[1]
lj_password = sys.argv[2]
encoding = sys.argv[3]
filename = sys.argv[4]

if filename == '-':
    file_object = open(sys.stdin)
else:
    try: file_object = open(filename,'r')
    except IOError:
      sys.stderr.write('Cannot open file' + filename + ', dying...\n')
      sys.exit(1)

'''
if sys.platform == 'win32':
  if filename == '-':
    file_object = open(sys.stdin)
  else:
    try: file_object = open(filename,'r')
    except IOError:
      sys.stderr.write('Cannot open file' + filename + ', dying...\n')
      sys.exit(1)
else:
  if filename == "-":
  	file_object = codecs.EncodedFile(sys.stdin, "utf-8", encoding) 
  else:
    try: file_object = codecs.EncodedFile(open(filename,"r"),"utf-8",encoding)
    except IOError:
      sys.stderr.write("Cannot Open file" + filename + ", dying..\n")
      sys.exit(1)
'''
# Now, we've got our message in file_object
# RFC822 it!
message = rfc822.Message(file_object)
post = {}

# Fill in password and username
post["user"] = lj_username
m_hash = md5.new(lj_password)
post["hpassword"] = m_hash.hexdigest()

# First, let's gather the RFC822 date out of the message, and parse it.
if message.has_key("Date"):
	date_tuple = message.getdate("Date")
else:
	# No date in message, that's ok, take current.
	date_tuple = time.localtime()

post["year"] = date_tuple[0]
post["mon"] = date_tuple[1]
post["day"] = date_tuple[2]
post["hour"] = date_tuple[3]
post["min"] = date_tuple[4]

# Next, take a journal to use.
if message.has_key("Journal"):
	# User may have put username in journalname. Check it.
	if (message.getheader("Journal")) != lj_username:
		# No. Ok, it's a community.
		post["usejournal"] = message.getheader("Journal")

# Next, take fetch subject out.
if message.has_key("Subject"):
	post["subject"] = message.getheader("Subject")
else:
	# Subject is _required_ to post :)
	sys.stderr.write("Subject is required to post, dying..\n")
	sys.exit(1)

# Now, get the mood
if message.has_key("Mood"):
	post["prop_current_mood"] = message.getheader("Mood")

# Any music now playing? 
if message.has_key("Music"):
	post["prop_current_music"] = message.getheader("Music")

# Preformat?
if message.has_key("Preformatted"):
	if re.match("yes", message.getheader("Preformatted"), 3):
		post["prop_opt_preformatted"] = 1

# Nocomments?
if message.has_key("Nocomments"):
	if re.match("yes", message.getheader("Nocomments"), 3):
		post["prop_opt_nocomments"] = 1

# Picture keyword?
if message.has_key("Picture"):
	post["prop_picture_keyword"] = message.getheader("Picture")

# Backdated?
if message.has_key("Backdated"):
	if re.match("yes", message.getheader("Backdated"), 3):
		post["prop_opt_backdated"] = 1

# No email?
if message.has_key("Noemail"):
	if re.match("yes", message.getheader("Noemail"), 3):
		post["prop_opt_noemail"] = 1

# Has screened posts?
if message.has_key("Hasscreened"):
	if re.match("yes", message.getheader("Hasscreened"), 3):
		post["prop_hasscreened"] = 1
  
# Security. Default is public.
if message.has_key("Security"):
	if re.match("private", message.getheader("Security"), 3):
		post["security"] = "private"

# Mode is postevent.
post["mode"] = "postevent"

# Version is 1
post["ver"] = "1"

# Body. Let's get the body.
message.rewindbody()

result_line = ""
bodylines = file_object.readlines()
for line in bodylines:
	result_line += line
post["event"] = result_line

# Setting up the Proxy Address
if False:
  proxy_ip = "10.10.10.10:80"
  proxy_user = "senthil_or"
  proxy_password_orig= "Password"
  proxy_password = urllib.quote(proxy_password_orig,"")

  # Setup the Proxy with urllib2

  proxy_url = 'http://' + proxy_user + ':' + proxy_password + '@' + proxy_ip
  proxy_support = urllib2.ProxyHandler({"http":proxy_url})
  opener = urllib2.build_opener(proxy_support,urllib2.HTTPHandler)
  urllib2.install_opener(opener)

urldata = urllib.urlencode(post)
result = urllib2.urlopen("http://www.livejournal.com/interface/flat", urldata)

resultlines = result.readlines()
for line in resultlines:
	print line,
