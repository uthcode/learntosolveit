import socket
import sys

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = sys.argv[1]
    port = int(sys.argv[2])
    s.connect((host, port))
    flo = s.makefile('r',0)
    for l in flo:
        print l

if __name__ == '__main__':
    main()
