import urllib2
import urllib
import urlparse
import sys

try:
    from BeautifulSoup import BeautifulSoup
except ImportError:
    print "Pre-requsite not met - BeautifulSoup library"
    sys.exit(-1)

try:
    import Image
except ImportError:
    print "Pre-requisite not met - Python Imaging library"
    sys.exit(-1)

URL = 'http://www.indochino.com/'
parsed_url = urlparse.urlparse(URL)
global_url = []
visited_url = []

def getimages(node):
    images = []
    try:
        soup = BeautifulSoup(urllib2.urlopen(URL))
        for image in soup.findAll("img"):
            img = image["src"]
            if img.split('.')[-1] in ('jpg','png','jpeg','gif'):
                parsed_img = urlparse.urlparse(img)
                if not parsed_img.scheme:
                    img = urlparse.urljoin(URL,parsed_img.path)
                images.append(img)
    except (IOError, KeyError, IndexError):
        pass
    return images

def childrenfun(node):
    if isinstance(node, list):
        return iter(node)
    else:
        links = []
        try:
            soup = BeautifulSoup(urllib2.urlopen(node))
            for l in soup.findAll("a"):
                l = l["href"]
                parsed = urlparse.urlparse(l)
                if (parsed.scheme and (parsed.scheme in ('http','https')) and (parsed.netloc in parsed_url.netloc)):
                    link = urlparse.urlunparse((parsed.scheme,parsed.netloc,parsed.path,'','',''))
                    if not link in global_url:
                        global_url.append(link)
                        links.append(link)
        except (IOError, KeyError):
            pass
        return links

def breadth_first(tree,children=childrenfun):
    """Traverse the nodes of a tree in breadth-first order.
    The first argument should be the tree root; children
    should be a function taking as argument a tree node and
    returning an iterator of the node's children.
    """
    yield tree
    last = tree
    for node in breadth_first(tree,children):
        for child in children(node):
            yield child
            last = child
        if last == node:
            return

node = URL
for n in breadth_first(node):
    if n not in visited_url:
        visited_url.append(n)
        for img in getimages(n):
            tmp_loc, hdrs = urllib.urlretrieve(img)
            im  = Image.open(tmp_loc)
            x, y = im.size
            if x > 10 and y > 10:
                print img
