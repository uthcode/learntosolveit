import BaseHTTPServer
import cgi, random, sys

MESSAGES = [
    "I like maxims that don't encourage behavior modification.",
    "Reality continues to ruin my life.",
    "Weekends don't count unless you spend them doing something completely \
    pointless.",
    "Life's disappointments are harder to take when you don't know any swear \
    words."
]

class Handler(BaseHTTPServer.BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path != "/":
            self.send_error(404,"File not Found!")
            return
        self.send_response(200)
        self.send_header("Content-type:", "text/html")
        self.end_headers()
        try:
            # redirect stdout to client
            stdout = sys.stdout
            sys.stdout = self.wfile
            self.makepage()
        finally:
            sys.stdout = stdout # restore

    def makepage(self):
        # generate a random message
        tagline = random.choice(MESSAGES)
        print "<html>"
        print "<body>"
        print "<p>Today's Quote:"
        print "<i>%s</i>" % cgi.escape(tagline)
        print "</body>"
        print "</html>"

PORT = 8000

httpd = BaseHTTPServer.HTTPServer(("",PORT), Handler)
print "serving at port", PORT
httpd.serve_forever()

