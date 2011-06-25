import xmlrpclib

proxy = xmlrpclib.ServerProxy('http://localhost:9000')

for method_name in proxy.system.listMethods():
    print '=' * 60
    print method_name
    print '-' * 60
    print proxy.system.methodHelp(method_name)
    print
