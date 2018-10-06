"""
Simple HTTP Server with GET that waits for given seconds.
"""

from http.server import BaseHTTPRequestHandler, HTTPServer
from socketserver import ThreadingMixIn
import time

ENCODING = 'utf-8'


class ThreadingHTTPServer(ThreadingMixIn, HTTPServer):
    """Simple multi-threaded HTTP Server."""
    pass


class MyRequestHandler(BaseHTTPRequestHandler):
    """Very simple request handler. Only supports GET."""

    def do_GET(self):
        """Respond after seconds given in path.
        """
        try:
            seconds = float(self.path[1:])
        except ValueError:
            seconds = 0.0

        if seconds < 0:
            seconds = 0.0

        text = "Waited for {:4.2f} seconds.\nThat's all.\n"
        msg = text.format(seconds).encode(ENCODING)
        time.sleep(seconds)

        self.send_response(200)
        self.send_header("Content-type", "text/plain; charset=utf-8")
        self.send_header("Content-length", str(len(msg)))
        self.end_headers()
        self.wfile.write(msg)


def run(server_class=ThreadingHTTPServer,
        handler_class=MyRequestHandler,
        port=8888):
    """Run the simple server on a given port."""
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    print("Serving from port {}...".format(port))
    httpd.serve_forever()


if __name__ == '__main__':
    run()
