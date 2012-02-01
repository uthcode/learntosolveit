from twisted.internet import epollreactor
epollreactor.install()
from twisted.internet import reactor
from twisted.web import server, resource

class Simple(resource.Resource):
    isLeaf = True
    def render_GET(self, request):
        return "Hello, world!"

site = server.Site(Simple())
reactor.listenTCP(8888, site)
reactor.run()
