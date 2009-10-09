def subhex(hex1, hex2):
    int1 = int(hex1, 16)
    int2 = int(hex2, 16)
    return '%X' % (int1-int2)

print subhex('0x6010c4','0x601060')
