import pickle
import Queue
import socket
import threading


# We'll pickle a list of numbers, yet again:

somelist = [1,2,7,9,0]
pickledlist = pickle.dumps(somelist)

# A revised version of the thread class

class ClientThread(threading.Thread):
    # Note that we do not override Thread's __init__ method
    # The Queue module makes this as not neccessary

    def run(self):
        # Have our thread serve "forever".
        while True:
            # Get a client out of the queue.
            client = clientPool.get()

            # Check if actually have an actual client in the client variable.

            if client != None:
                print 'Received Connection:', client[1][0]
                client[0].send(pickledlist)
                for x in xrange(10):
                    print client[0].recv(1024)

                client[0].close()
                print 'Closed Connection:', client[1][0]



# Create our Queue

clientPool = Queue.Queue(0)

# Start two threads
for x in xrange(2):
    ClientThread().start()

# Setup the server
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('', 2727))
server.listen(5)

# Have the server 'serve' forever

while True:
    clientPool.put(server.accept())

