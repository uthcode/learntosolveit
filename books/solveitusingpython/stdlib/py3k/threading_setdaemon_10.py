import threading
import time

class DaemonThread(threading.Thread):
    def run(self):
        self.setDaemon(True)
        time.sleep(10)

DaemonThread().start()
print 'Leaving.'
