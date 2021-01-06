import socket

def get_constants(prefix):
    """Create a dictionary mapping socket module constants to their names."""
    return dict( (getattr(socket, n), n)
                 for n in dir(socket)
                 if n.startswith(prefix)
                 )

families = get_constants('AF_')
print(families)
types = get_constants('SOCK_')
print(types)
protocols = get_constants('IPPROTO_')
print(protocols)

for response in socket.getaddrinfo('endhiroid.blogspot.com', 'http',
                                   socket.AF_INET,      # family
                                   socket.SOCK_STREAM,  # socktype
                                   socket.IPPROTO_TCP,  # protocol
                                   socket.AI_CANONNAME, # flags
                                   ):
    # Unpack the response tuple
    family, socktype, proto, canonname, sockaddr = response

    print('Family        :', families[family])
    print('Type          :', types[socktype])
    print('Protocol      :', protocols[proto])
    print('Canonical name:', canonname)
    print('Socket address:', sockaddr)
    print()
