import socket
import sys

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('',54557))

server_address = ('localhost', 10000)
message = 'This is the message.  It will be repeated.'

try:

    # Send data
    print('sending "%s"' % message, file=sys.stderr)
    sent = sock.sendto(message, server_address)
    print(sock.getsockname()[1])

    # Receive response
    print('waiting to receive', file=sys.stderr)
    data, server = sock.recvfrom(4096)
    print('received "%s"' % data, file=sys.stderr)

finally:
    print('closing socket', file=sys.stderr)
    sock.close()
