import threading

class TestThread(threading.Thread):
    def run(self):
        print 'Hello, my name is', self.getName()


bombay = TestThread()
bombay.setName('bombay')
bombay.start()


madras = TestThread()
madras.setName('madras')
madras.start()


TestThread().start()
TestThread().start()
bangalore = TestThread()
bangalore.setName('bangalore')
bangalore.start()
TestThread().start()

