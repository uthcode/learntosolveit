import string

def hexlify(a):
    out = []
    for i in a:
        a1 = ord(i) % 16
        if a1 > 10:
            a1 = a1-10 + ord('A')
        if a1 < 10:
            a1 = a1    + ord('0')

        a2 = ord(i) / 16
        if a2 > 10:
            a2 = a2-10 + ord('A')
        if a2 < 10:
            a2 = a2 + ord('0')

        out.append(chr(a2))
        out.append(chr(a1))

    return string.join(out,'')

print hexlify('hello')


# Derive the algorithm for encoding a string in hexadecimal.
# hexadecimal has 0-9, A,B,C,D,E,F
# What is 'a' in hexadecimal?
# What is 'b' in hexadecimal?
# What is 'A' in hexadecimal?
# What is 'Z' in hexadecimal?
# What is 101 in hexadecimal?
# What is 42 in hexadecimal?

#'a' in decimal is ASCII Chart is 97.
# Convert 97 in base 10 to x in base 16.
# Convert 97 in base 10 to x in base 2

 
