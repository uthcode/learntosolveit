import threading
import urllib.request, urllib.parse, urllib.error

class MultiUrl(threading.Thread):
    def __init__(self, url):
        threading.Thread.__init__(self)
        self.url = url
    def run(self):
        urllib.request.urlopen(self.url).read()

background = MultiUrl('http://slashdot.org')
background.start()
print('main continues')
background.join()
print('main is done.')
