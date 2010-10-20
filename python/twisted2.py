"""
How is the out value passed to the function1?

utils.getProcessOutput function is returning a deffered object.
You attach a callback function to the deferred object.
When the defered is ready with the result, the callback function is called with
it. That is what is happening here.

"""

from twisted.internet import utils, reactor

def function1(out):
    print out
    reactor.stop()
output = utils.getProcessOutput('ls')
output.addCallback(function1)
reactor.run()
