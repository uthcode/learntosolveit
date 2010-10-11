from twisted.internet import utils, reactor

def function1(out):
    print out
    reactor.stop()
output = utils.getProcessOutput('ls')
output.addCallback(function1)
reactor.run()
