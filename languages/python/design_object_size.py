import pickle
import sys

obj = list(range(10000))

def GetMemoryUsage(ob):
    s = pickle.dumps(ob)
    memUsed = sys.getpymemalloced()
    ob2 = pickle.loads(s)
    return sys.getpymemalloced() - memUsed

print(GetMemoryUsage(obj))
