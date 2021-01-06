# {PI} {Sigma} {Omega} as ISO-8859-7 encoded string
b = '\xd0\xd3\xd9'

# Convert to Unicode ('universal format')
u = str(b, 'iso-8859-7')
print(repr(u))

# and back to ISO-8859-7
c = u.encode('iso-8859-7')
print(repr(c))
