import threading

def appstart():
    print('Start your dev_appserver')
    # Do operations

def coveragestart():
    print('Start your coverage')
    # Do operations

t = threading.Thread(name='start', target=appstart)
w = threading.Thread(name='stop', target=coveragestart)
t.start()
w.start()
w.join() # Note that I am joing coveragestart first
t.join()
