from threading import Thread
import time

def myfunc():
    print "hello, world"
    time.sleep(4)

thread1 = Thread(target=myfunc)
thread1.start()
thread1.join(timeout=5)
print thread1.isAlive()
