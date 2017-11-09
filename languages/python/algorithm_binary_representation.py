#!/usr/bin/python
"""
Program to do binary representation of various interesting ints.
"""


def convert_to_binary(n):
    binary = []
    while n:
        binary.append(str(n%2))
        n/=2
    binary.reverse()
    return "".join(binary)


for i in range(20,30):
    print(i, convert_to_binary(i))

hexa_values = ['0','1','A','FF','DEADBEEF','CAFEBABE']
for each in hexa_values:
    dec = int(each, 16)
    print(each, convert_to_binary(dec))

"""
Find out if the machine is storing it in the one's complement or two's
complement.
1 is stored as 0000 0001
-1 in 1's complement is 1111 1110
-1 in 2's complement is 1111 1111
"""

import struct

if (ord(struct.pack('b',-1)[0]) == 255):
    print('twos complement')
else:
    print('ones complement')

for i in range(200,255):
    print(hex(i))

for i in range(0,256):
    print(chr(i), i, hex(i))

"""
Binary Addition and Subtraction
"""
a = 20
b = 10

a_bin = convert_to_binary(a)
b_bin = convert_to_binary(b)

if (len(a_bin) > len(b_bin)):
    b_bin = b_bin.rjust(len(a_bin),'0')
elif (len(a_bin) < len(b_bin)):
    a_bin = a_bin.rjust(len(b_bin),'0')

def sum_bin(a, b):
    rules = {('0', '0'):(0,0),
             ('0', '1'):(1,0),
             ('1', '0'):(1,0),
             ('1', '1'):(0,1)
            }
    carry = 0
    sum = 0
    result = ""
    for x,y in zip(reversed(a),reversed(b)):
        sum = rules[(x,y)][0]
        if carry:
            sum = rules[(str(sum), str(carry))][0]
        result += str(sum)
        carry = rules[(x,y)][1]

    if carry:
        result += str(1)

    return result[::-1]

def sub_bin(a, b):
    ones_complement = ""
    for c in b:
        if c == '0':
            ones_complement += '1'
        elif c == '1':
            ones_complement += '0'

    b = ones_complement
    b = sum_bin(b,'1'.rjust(len(b),'0'))

    rules = {('0', '0'):(0,0),
             ('0', '1'):(1,0),
             ('1', '0'):(1,0),
             ('1', '1'):(0,1)
            }

    carry = 0
    sum = 0
    result = ""
    for x,y in zip(reversed(a),reversed(b)):
        sum = rules[(x,y)][0]
        if carry:
            sum = rules[(str(sum), str(carry))][0]
        result += str(sum)
        carry = rules[(x,y)][1]

    # unlike addition carry should be discarded.

    return result[::-1]


print('a', a, a_bin)
print('b', b, b_bin)

print('a+b ',sum_bin(a_bin, b_bin))
print('a-b ',sub_bin(a_bin, b_bin))
