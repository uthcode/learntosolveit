#!/usr/bin/env python
import cgi
form = cgi.FieldStorage() # instantiate only once!
name = form.getfirst('name', 'empty')

# Avoid script injection escaping the user input
name = cgi.escape(name)

print """\
Content-Type: text/html\n
<html><body>
<p>The submitted name was "%s"</p>
</body></html>
""" % name
