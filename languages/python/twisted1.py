#import pudb
#pudb.set_trace()
from twisted.internet import task
from twisted.internet import reactor

def runEverySecond():
    print "a second has passed"

l = task.LoopingCall(runEverySecond)
l.start(1.0) # call every second

# l.stop() will stop the looping calls
reactor.run()
