import threading
import time


class ThreadOne(threading.Thread):
    def run(self):
        print 'Thread', self.getName(), 'started.'
        time.sleep(5)
        print 'Thread', self.getName(), 'ended.'


class ThreadTwo(threading.Thread):
    def run(self):
        print 'Thread', self.getName(), 'started.'
        thingOne.join()
        print 'Thread', self.getName(), 'ended.'

thingOne = ThreadOne()
thingOne.start()
thingTwo = ThreadTwo()
thingTwo.start()
