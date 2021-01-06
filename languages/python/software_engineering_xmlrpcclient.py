import xmlrpc.client
proxy = xmlrpc.client.ServerProxy('http://localhost:9000')

# Call expliciting registered function

print('dir():',proxy.dir('/'))
try:
    print('list_contents():', proxy.list_contents('/'))
except:
    print('You should use a registered name.')

# Call the standard functions registered with server
print('BEFORE:', 'EXAMPLE' in proxy.dir.list('/tmp'))
print('CREATE:', proxy.dir.create('/tmp/EXAMPLE'))
print('SHOULD EXIST:', 'EXAMPLE' in proxy.dir.list('/tmp'))
print('REMOVE:', proxy.dir.remove('/tmp/EXAMPLE'))
print('AFTER', 'EXAMPLE' in proxy.dir.list('/tmp'))


# Call the function (handler) which has space
print(getattr(proxy,'my func')(5,5))
