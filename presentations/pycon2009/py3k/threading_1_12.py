from threading import Thread

class myObject(Thread):
    def __init__(self):
        self._val = 1
    def get(self):
        return self._val
    def increment(self):
        self._val += 1

def t1(ob):
    ob.increment()
    print 't1:', ob.get() == 2

def t2(ob):
    ob.increment()
    print 't2:', ob.get() == 2

ob = myObject()

# Create two threads modifying the same ob instance

thread1 = Thread(target=t1, args=(ob,))
thread2 = Thread(target=t2, args=(ob,))


# Run the thread

thread1.start()
thread2.start()
thread1.join()
thread2.join()

