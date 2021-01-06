#:w/usr/bin/python
# $Id$
"""
List Network Interfaces

**Purpose**: This program  provides list of network interfaces available on
your machine.

**Description**: man netdevice provides the following information about
SIOCGIFCONF which is used to retrieve the interfaces information.

SIOCGIFCONF

Return a list of interface (transport layer) addresses. This currently means
only addresses of the AF_INET (IPv4) family for compatibility. The user passes
a ifconf structure as argument to the ioctl. It contains a pointer to an array
of ifreq structures in ifc_req and its length in bytes in ifc_len. The kernel
fills the ifreqs with all current L3 interface addresses that are running:
ifr_name contains the interface name (eth0:1 etc.), ifr_addr the address.  The
kernel returns with the actual length in ifc_len. If ifc_len is equal to the
original length the buffer probably has overflowed and you should retry with a
bigger buffer to get all addresses. When no error occurs the ioctl returns 0;
otherwise -1. Overflow is not an error.

"""

import socket
import fcntl
import struct
import array

def all_interfaces():
    max_possible = 128  # arbitrary. raise if needed.
    bytes = max_possible * 32
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    names = array.array('B', '\0' * bytes)
    outbytes = struct.unpack('iL', fcntl.ioctl(
        s.fileno(),
        0x8912,  # SIOCGIFCONF
        struct.pack('iL', bytes, names.buffer_info()[0])
    ))[0]
    namestr = names.tostring()
    return [namestr[i:i+32].split('\0', 1)[0] for i in range(0, outbytes, 32)]

print(all_interfaces())
