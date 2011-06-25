import threading
import time

class TestThread(threading.Thread):
    def run(self):
        print 'Patient: Doctor, am I going to die?'

class AnotherThread(TestThread):
    def run(self):
        TestThread.run(self)
        time.sleep(10)

dying = TestThread()
dying.start()

if dying.isAlive():
    print 'Doctor, No'
else:
    print 'Oops. Dead before I could do anything. Next!'

living = AnotherThread()
living.start()

if living.isAlive():
    print 'Doctor:No'
else:
    print 'Doctor: Next!'


