import urllib

url = 'http://uthcode.sarovar.org/~senthil'
print 'urlencode():', urllib.urlencode({'url':url})
print 'quote():', urllib.quote(url)
print 'quote_plus():', urllib.quote_plus(url)

quoted = urllib.quote(url)
quoteplused = urllib.quote_plus(url)

print 'unquote', urllib.unquote(quoted)
print 'unquote_plus', urllib.unquote_plus(quoteplused)

