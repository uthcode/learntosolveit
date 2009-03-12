from threading import Thread

class MyThread(Thread):
    def run(self):
        print "I am a thread!"

foobar = MyThread()
foobar.start()
foobar.join()
