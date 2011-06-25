import urllib

response = urllib.urlopen('http://localhost:8080/')
print 'RESPONSE:', response
print 'URL      :', response.geturl()

headers = response.info()

print 'DATE:', headers['date']
print 'HEADERS:'
print '--------'
print headers

data = response.read()
print 'LENGTH   :', len(data)
print 'DATA     :'
print '----------'
print data
