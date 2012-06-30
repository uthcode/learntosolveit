#!/usr/bin/python

import sha, shelve, time, Cookie, os

class Session(object):

   def __init__(self, expires=None, cookie_path=None):
      string_cookie = os.environ.get('HTTP_COOKIE', '')
      self.cookie = Cookie.SimpleCookie()
      self.cookie.load(string_cookie)

      if self.cookie.get('sid'):
         sid = self.cookie['sid'].value
         # Clear session cookie from other cookies
         self.cookie.clear()

      else:
         self.cookie.clear()
         sid = sha.new(repr(time.time())).hexdigest()

      self.cookie['sid'] = sid

      if cookie_path:
         self.cookie['sid']['path'] = cookie_path

      session_dir = os.environ['DOCUMENT_ROOT'] + '/session'
      if not os.path.exists(session_dir):
         try:
            os.mkdir(session_dir, 02770)
         # If the apache user can't create it create it manualy
         except OSError, e:
            errmsg =  """%s when trying to create the session directory. \
Create it as '%s'""" % (e.strerror, os.path.abspath(session_dir))
            raise OSError, errmsg
      self.data = shelve.open(session_dir + '/sess_' + sid, writeback=True)
      os.chmod(session_dir + '/sess_' + sid, 0660)

      # Initializes the expires data
      if not self.data.get('cookie'):
         self.data['cookie'] = {'expires':''}

      self.set_expires(expires)

   def close(self):
      self.data.close()

   def set_expires(self, expires=None):
      if expires == '':
         self.data['cookie']['expires'] = ''
      elif isinstance(expires, int):
         self.data['cookie']['expires'] = expires

      self.cookie['sid']['expires'] = self.data['cookie']['expires']
