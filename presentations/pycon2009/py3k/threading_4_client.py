import pickle
import socket


# Connect to the Server

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((('localhost'), 2727))

print pickle.loads(client.recv(1024))


# Send some messages

for x in xrange(10):
    client.send('Hey,' + str(x) + '\n')

# Close the connection

client.close()
