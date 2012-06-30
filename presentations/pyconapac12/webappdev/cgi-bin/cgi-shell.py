#!/usr/bin/python
import cgitb; cgitb.enable()
import sys, os
sys.path.append(os.path.dirname(os.environ['SCRIPT_FILENAME']))
import session, time, cgi, urllib, subprocess as sub

def login(form, sess):
   # You absolutely need to change these !!!
   passwords = {'me':'mine', 'friend':'his'}
   username = form.getfirst('username', '')
   password = form.getfirst('password', '')
   if username and passwords.get(username) == password:
      sess.set_expires(365 * 24 * 60 * 60)
      sess.data['logged'] = True
      sess.data['logged_until'] = time.time() + 10 * 60
      sess.data['empty_cmd'] = False
      return True
   if not username or not password:
      message = 'Enter user name and password to log into CGI Shell'
   elif username not in passwords or passwords.get(username) != password:
      message = 'Wrong username or password'
   onload = """var el = document.getElementById('un'); el.focus();
      el.select()"""
   header(sess, onload)
   print """\
   <div style="border:3px solid gray;width:350px;height:130px;
      margin:auto;padding:20px;" class="shell">
   <p>%s</p>
   <form method="post" action="./cgi-shell.py">
   <p>Username: <input type="text" name="username" id="un" value="%s"
      class="shell" style="border:1px lime solid;padding:2px 4px;" /></p>
   <p>Password: <input type="password" name="password"
      class="shell" style="border:1px lime solid;padding:2px 4px;" /></p>
   <p style="text-align:center;"><input type="submit" value="Login" class="button" /></p>
   </form>
   </div>
   """ % (message, username)
   return False

def end(sess):
   print '</body>\n</html>'
   sess.close()
   sys.exit(0)

def shell(form, sess):
   sess.data['logged_until'] = time.time() + 10 * 60
   sess.data.setdefault('output', [])
   cmd = form.getfirst('cmd', '')
   cur_dir = sess.data.setdefault('pwd', os.environ['DOCUMENT_ROOT'])
   if cmd or cmd == '' and sess.data['empty_cmd']:
      sess.data['cmd'] = cmd
      cmd = urllib.unquote(cmd)
      p = sub.Popen(['/bin/bash', '-c', cmd + '\necho $PWD'],
         stdout=sub.PIPE, stderr=sub.STDOUT, cwd=cur_dir)
      prompt = '[@' + os.environ['SERVER_NAME'] + ' '
      prompt += os.path.basename(cur_dir) + ']$ '
      output = [prompt + cmd + '\n'] + p.stdout.readlines()
      sess.data['pwd'] = (output[-1:])[0].rstrip()
      sess.data['output'] = (sess.data['output'] + output)[-501:-1]
   else:
      cmd = urllib.unquote(sess.data.setdefault('cmd', ''))
   sess.data['empty_cmd'] = True
   cur_dir = sess.data['pwd']
   output = cgi.escape(''.join(sess.data['output']).rstrip(), True)
   onload = """window.location.href = '#last';
      var el = document.getElementById('cmd');el.focus();el.select();"""
   prompt = '[&#064;' + os.environ['SERVER_NAME'] + ' '
   prompt += os.path.basename(cur_dir) + ']$ '
   header(sess, onload)
   print """\
<div style="width:98%%;margin:0;">
<pre style="border-bottom:0;margin:0;padding:6px;width:100%%;
   overflow:auto;height:430px;border:3px solid gray;border-bottom:0;"
   class="shell" id="output">%s<span id="last"></span></pre>
<form method="post" action="#last">
<p style="margin:0;padding:6px 6px 8px;width:100%%;border:3px solid gray;
   border-top:0;" class="shell">%s
   <input type="text" name="cmd" value="%s" class="shell" id="cmd"
   style="width:55%%;border:1px lime solid;padding:2px 4px;" />
<input type="submit" value="Submit" name="submit" class="button" />
<input type="submit" value="Logout" name="submit" class="button" /></p>
</form>
</div>
""" % (output, prompt, cgi.escape(cmd, True))
   end(sess)

def header(sess, onload=''):
   print """\
%s
Content-Type: text/html\n
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>\n<head><title>CGI Shell</title>
<style type="text/css">
.shell {font-size:12px;font-family:monospace;background-color:black;color:lime;}
</style>\n</head>
<body onload="%s" style="background-color:lightgray;font-family:monospace;">
<h2 style="text-align:center;margin:8px auto">CGI Shell</h2>
""" % (sess.cookie, onload)

def main():
   sess = session.Session()
   form = cgi.FieldStorage()
   if form.getfirst('submit') == 'Logout' or \
      sess.data.get('logged_until', 0) < time.time():
      sess.data['logged'] = False
   if not sess.data.get('logged') and not login(form, sess):
      end(sess)
   shell(form, sess)

main()
