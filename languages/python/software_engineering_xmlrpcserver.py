from xmlrpc.server import SimpleXMLRPCServer
import logging
import os

# Set up logging
logging.basicConfig(level=logging.DEBUG)

server = SimpleXMLRPCServer(('localhost',9000),logRequests=True,
        allow_none=True)

# Expose a function

def list_contents(dir_name):
    logging.debug('list_contents(%s)', dir_name)
    return os.listdir(dir_name)

server.register_function(list_contents,'dir')

# Register the Standard os functions

server.register_function(os.listdir,'dir.list')
server.register_function(os.mkdir,'dir.create')
server.register_function(os.rmdir,'dir.remove')


# Expose a function

def my_func(a, b):
    return a * b

# my func handler has space in between not
# a valid function name, but still it can be called.

server.register_function(my_func,'my func') 

try:
    print('Use Control-C to exit')
    server.serve_forever()
except KeyboardInterrupt:
    print('Exiting!')

