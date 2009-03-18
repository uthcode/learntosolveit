import xmlrpclib

proxy = xmlrpclib.ServerProxy('http://localhost:9000')
print 'BEFORE   :', 'Example' in proxy.dir.list('/home/senthil')
print 'CREATE   :', proxy.dir.create('/home/senthil/Example')
print 'SHOULD EXIST :', 'Example' in proxy.dir.list('/home/senthil/')
print 'REMOVE   :', proxy.dir.remove('/home/senthil/Example')
print 'AFTER    :', 'Example' in proxy.dir.list('/home/senthil')
