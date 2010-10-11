import cPickle
import sys

obj = range(10000)

def GetMemoryUsage(ob):
    s = cPickle.dumps(ob)
    memUsed = sys.getpymemalloced()
    ob2 = cPickle.loads(s)
    return sys.getpymemalloced() - memUsed

print GetMemoryUsage(obj)
