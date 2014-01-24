import urllib
import urllib2
url = 'http://codepad.org'

#with open('helloworld.c') as fd:
#    code = fd.read()

code = "print"

values = {'lang' : 'Python',
          'code' : code,
          'submit':'Submit'}
data = urllib.urlencode(values)
print data

#response = urllib2.urlopen(url, data)
#the_page = response.geturl()
#print the_page + '/fork'
"""
for href in the_page.split("</a>"):
    if "Link:" in href:
        ind=href.index('Link:')
        found = href[ind+5:]
        for i in found.split('">'):
            if '<a href=' in i:
                 print "The link: " ,i.replace('<a href="',"").strip()
"""
