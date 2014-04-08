from socket import *
from struct import unpack
from time import ctime, sleep
from sys import argv

argv = argv[1:]
if len(argv) == 0:
   argv = [ 'time-nw.nist.gov' ]

s = socket(AF_INET, SOCK_DGRAM)
s.settimeout(5.0)

for server in argv:
   print server, ":",
   try:
       s.sendto('', 0, (server, 37))
       t = long(unpack('!L', s.recv(16)[:4])[0])
       # Convert from 1900/01/01 epoch to 1970/01/01 epoch
       t -= 2208988800
       print ctime(t)
   except timeout:
       print "TIMEOUT"
   except:
       print "ERROR"

s.close()
