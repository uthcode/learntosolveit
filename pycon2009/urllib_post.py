import urllib

query_args = {'q':'query string', 'foo':'bar'}
encoded_args = urllib.urlencode(query_args)
url = 'http://localhost:8000/'
print urllib.urlopen(url, encoded_args).read()
