import urllib2
import urllib

url = 'http://codepad.org'

with open('locate.py') as f:
    code = f.read()

parameters = {'project':'uthcode',
        'lang':'Python',
        'code': code,
        'private':'',
        'run':'False',
        'submit':'Submit'}

seq = urllib.urlencode(parameters)
r = urllib2.urlopen(url,seq)
print r.url + '/fork'
