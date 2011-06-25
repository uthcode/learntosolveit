import pickle
import socket
import threading

# We will pickle a list of numbers

somelist = [1, 2, 7, 9, 0]
pickledlist = pickle.dumps(somelist)


# Our thread class

class ClientThread(threading.Thread):

    # Override Thread's __init__ method to accept the parameters needed.
    def __init__(self, channel, details):
        self.channel = channel
        self.details = details
        threading.Thread.__init__(self)

    def run(self):
        print 'Received Connection:', self.details[0]
        self.channel.send(pickledlist)
        for x in xrange(10):
            print self.channel.recv(1024)
        self.channel.close()
        print 'Closed Connection:', self.details[0]


# Setup the server
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('',2727))
server.listen(5)

# Have the server serve forever
while True:
    channel, details = server.accept()
    ClientThread(channel, details).start()

