import re
import urllib.request, urllib.parse, urllib.error

regex = re.compile(r'href="([^"]+)"')

def matcher(url, max=10):
    """Print the first several URL references in the given URL"""
    data = urllib.request.urlopen(url).read()
    hits = regex.findall(data)
    for hit in hits[:max]:
        print(urllib.basejoin(url,hit))

matcher("http://uthcode.sarovar.org")
