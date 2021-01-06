"""
Synchronous client to retrieve web pages.
"""

from urllib.request import urlopen
import time

ENCODING = 'ISO-8859-1'


def get_encoding(http_response):
    """Find out encoding."""
    content_type = http_response.getheader("Content-type")
    for entry in content_type.split(";"):
        if entry.strip().startswith('charset'):
            return entry.split('=')[1].strip()
    return ENCODING


def get_page(host, port, wait=0):
    """Get one page suppling 'wait' time.

    The path will be build with 'host:port/wait'
    """
    full_url = '{}:{}/{}'.format(host, port, wait)
    with urlopen(full_url) as http_response:
        html = http_response.read().decode(get_encoding(http_response))
    return html


def get_multiple_pages(host, port, waits, show_time=True):
    """Get multiple pages."""

    start = time.perf_counter()
    pages = [get_page(host, port, wait) for wait in waits]
    duration = time.perf_counter() - start
    sum_waits = sum(waits)

    if show_time:
        msg = "It took {:4.2f} seconds for a total waiting time of {:4.2f}."
        print((msg.format(duration, sum_waits)))

    return pages

if __name__ == '__main__':

    def main():
        """Test it."""
        pages = get_multiple_pages(
                    host='http://localhost',
                    port='8888',
                    waits=[1, 5, 3, 2])
        for page in pages:
            print(page)

    main()

