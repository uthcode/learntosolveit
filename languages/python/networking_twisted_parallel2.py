#!/usr/bin/python2.6

from twisted.internet import defer, task
from twisted.python import log
from twisted.internet import reactor
from twisted.web import client
from twisted.internet.utils import getProcessValue

executable = '/home/senthil/uthcode/python/sometask'

def parallel(count=None):
    coop = task.Cooperator()
    work = (getProcessValue(executable) for i in range(10))
    if count:
        return defer.DeferredList([coop.coiterate(work) for i in range(count)])
    else:
        return coop.coiterate(work)

finished = parallel()
finished.addErrback(log.err)
finished.addCallback(lambda ign: reactor.stop())
reactor.run()
