# Instead of a single thread, create a group of threads.

import threading

theVar = 1

class MyThread(threading.Thread):

    def run(self):
        global theVar
        print 'This is a thread' + str(theVar) + 'speaking'
        print 'Hello and Good Bye'
        theVar = theVar + 1


for x in xrange(20):
    MyThread().start()
