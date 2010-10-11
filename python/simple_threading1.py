import threading
import urllib
import pudb
pudb.set_trace()

class MultiUrl(threading.Thread):
    def __init__(self, url):
        threading.Thread.__init__(self)
        self.url = url
    def run(self):
        urllib.urlopen(self.url).read()

background = MultiUrl('http://slashdot.org')
background.start()
print 'main continues'
background.join()
print 'main is done.'
