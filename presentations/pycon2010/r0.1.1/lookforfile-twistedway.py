import os
from twisted.internet import reactor, defer

LOGDIR = 'logsdir'

def dataextract(filename):
    dirloc = os.path.join(os.getcwd(),LOGDIR)
    filepath = os.path.join(dirloc,filename)
    fh = open(filepath)
    print fh.read()
    fh.close()
    reactor.stop()

def getaccesstime(dir,filename):
    return os.stat(os.path.join(dir,filename)).st_atime

def getnewfile(directory):
    dirloc = os.path.join(os.getcwd(), directory)
    accessedcontents = []
    dircontents = os.listdir(dirloc)
    if (set(dircontents) - set(accessedcontents)):
        newfileset = set(dircontents) - set(accessedcontents)
        newfile = newfileset.pop()
        accessedcontents = dircontents[:]
        return newfile
    else:
        return None

def monitor(directory,d=None):
    if not d:
        d = defer.Deferred()
    newfile = getnewfile(directory)
    if not newfile:
        reactor.callLater(1, monitor, directory, d)
    else:
        d.callback(newfile)

    return d

deferredobject = monitor(LOGDIR)
deferredobject.addCallback(dataextract)

reactor.run()
