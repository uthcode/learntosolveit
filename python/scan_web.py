import re
import urllib

regex = re.compile(r'href="([^"]+)"')

def matcher(url, max=10):
    """Print the first several URL references in the given URL"""
    data = urllib.urlopen(url).read()
    hits = regex.findall(data)
    for hit in hits[:max]:
        print urllib.basejoin(url,hit)

matcher("http://uthcode.sarovar.org")
