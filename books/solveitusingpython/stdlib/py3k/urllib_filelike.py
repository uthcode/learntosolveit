import urllib

response = urllib.urlopen('http://www.example.com')

for line in response:
    print line.rstrip()
