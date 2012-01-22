import threading

class MyThread(threading.Thread):

    def run(self):
        print 'Insert some thread stuff here.'
        print 'It will be executed.'
        print 'There is nothing much here.'

# To create a thread, just call its start() method.
# That is it.

MyThread().start()

