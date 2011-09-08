import urllib2
import urllib
import urlparse
import sys
import re
import optparse

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

parsed_url = urlparse.urlparse(URL) # for default
global_url = []
visited_url = []

def getimages(page):
    images = []
    try:
        soup = BeautifulSoup(urllib2.urlopen(page))
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

def guess_product_page(page):
    try:
        soup = BeautifulSoup(urllib2.urlopen(page))
    except (IOError,KeyError):
        return False
    american_currency = soup.findAll(text=re.compile('\$\d+(\.\d{2})?'))
    other_indicators = soup.findAll(text=['discount','free', 'product details','shipping'])
    if len(american_currency) > 2 or len(other_indicators) > 2:
        return True
    else:
        return False

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

if __name__ == '__main__':
    option_parser = optparse.OptionParser()
    option_parser.add_option('-x','--height',dest='height',default=100,type="int")
    option_parser.add_option('-y','--width', dest='width', default=100,type="int")
    option_parser.add_option('-g',dest='guess',action='store_true',default=False)

    (options, args) = option_parser.parse_args()

    if len(args) == 0:
        node = URL
    else:
        node = args[0]
        try:
            parsed_url = urlparse.urlparse(node)
        except ValueError:
            print 'Invalid URL', node
            sys.exit(-1)

    for n in breadth_first(node):
        if n not in visited_url:
            visited_url.append(n)
            print 'URL %s' % n,
            if options.guess:
                product_page = guess_product_page(n)
                if product_page:
                    print 'is a Product Page'
                else:
                    print 'is not a Product Page'
            for img in getimages(n):
                tmp_loc, hdrs = urllib.urlretrieve(img)
                try:
                    im  = Image.open(tmp_loc)
                    width, height = im.size
                    if width >= options.height and height >= options.width:
                        print '%d %d %s' % (width, height, img)
                except Exception as exc:
                    print 'Did not check size: %s' % img
