import struct
print struct.pack("BHB",1,2,3)
print struct.pack("!BHB",1,2,3)
print struct.calcsize("BHB")
print struct.calcsize("!BHB")
