#!/usr/bin/env python
import cgi
form = cgi.FieldStorage()

# getlist() returns a list containing the
# values of the fields with the given name
colors = form.getlist('color')

print "Content-Type: text/html\n"
print '<html><body>'
print 'The colors list:', colors
for color in colors:
   print '<p>', cgi.escape(color), '</p>'
print '</body></html>'
