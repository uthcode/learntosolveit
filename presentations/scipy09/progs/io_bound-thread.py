from threading import Thread
import urllib2

def getpage(url):
    for i in range(100):
        try:
            req = urllib2.Request(url)
            obj = urllib2.urlopen(req)
            page = obj.read()
        except IOError:
            print 'connection failure'

t1 = Thread(target=getpage, args=('http://uthcode.sarovar.org',))
t1.start()
t2 = Thread(target=getpage, args=('http://uthcode.sarovar.org',))
t2.start()
t1.join()
t2.join()
