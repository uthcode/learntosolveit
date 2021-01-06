from twisted.internet import defer, task
from twisted.python import log
from twisted.internet import reactor
from twisted.web import client
from twisted.internet.utils import getProcessValue

def parallel(iterable, count, callable, *args, **named):
    print(args, named)
    coop = task.Cooperator()
    work = (callable(elem, *args, **named) for elem in iterable)
    return defer.DeferredList([coop.coiterate(work) for i in range(count)])

def download(xxx_todo_changeme):
    (url, fileName) = xxx_todo_changeme
    return client.downloadPage(url, file(fileName, 'wb'))

urls = [(url, str(n)) for (n, url) in enumerate(file('urls.txt'))]
finished = parallel(urls, 50, download)
finished.addErrback(log.err)
finished.addCallback(lambda ign: reactor.stop())
reactor.run()
