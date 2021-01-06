import urllib.request, urllib.error, urllib.parse
import urllib.request, urllib.parse, urllib.error

url = 'http://www.someserver.com/cgi-bin/register.cgi'
user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
values = {'name':'Micheal Frood',
          'location':'Northampton',
          'language':'Python'
          }
headers = {'User-Agent':user_agent}

data = urllib.parse.urlencode(values)
req = urllib.request.Request(url, data, headers)
response = urllib.request.urlopen(req)
the_page = response.read()
print(the_page)
