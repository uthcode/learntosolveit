import socket
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the port
server_address = ('localhost', 10000)
print('starting up on %s port %s' % server_address, file=sys.stderr)
sock.bind(server_address)
while True:
    print('\nwaiting to receive message', file=sys.stderr)
    data, address = sock.recvfrom(4096)

    print('received %s bytes from %s' % (len(data), address), file=sys.stderr)
    print(data, file=sys.stderr)

    if data:
        sent = sock.sendto(data, address)
        print('sent %s bytes back to %s' % (sent, address), file=sys.stderr)
