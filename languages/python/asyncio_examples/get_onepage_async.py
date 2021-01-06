"""
Get a web page asynchronously.
"""

import asyncio
import random
import time

from contextlib import closing

ENCODING = "ISO-8859-1"


def get_encoding(header):
    """File out encoding."""
    for line in header:
        if line.lstrip().startswith("Content-type"):
            for entry in line.split(";"):
                if entry.strip().startswith('charset'):
                    return entry.split('=')[1].strip()
    return ENCODING


async def get_page(host, port, wait=0):
    """Get a web-page asynchronously."""
    reader, writer = await asyncio.open_connection(host, port)
    writer.write(
        b'\r\n'.join([
            'GET /{} HTTP/1.0'.format(wait).encode(ENCODING),
            b'Host: %b' % host.encode(ENCODING),
            b'Connection: close',
            b'',
            b'']))
    header = []
    msg_lines = []
    async for raw_line in reader:
        line = raw_line.decode(ENCODING).strip()
        if not line.strip():
            break
        header.append(line)
    encoding = get_encoding(header)
    async for raw_line in reader:
        line = raw_line.decode(encoding).strip()
        msg_lines.append(line)
    writer.close()
    return "\n".join(msg_lines)


def get_multiple_pages(host, port, waits, show_time=True):
    """Get multiple pages."""
    start = time.perf_counter()
    pages = []
    with closing(asyncio.get_event_loop()) as loop:
        for wait in waits:
            pages.append(loop.run_until_complete(get_page(host, port,wait)))
    duration = time.perf_counter() - start
    sum_waits = sum(waits)
    if show_time:
        msg = "It took {:4.2f} seconds for a total waiting time of {:4.2f}."
        print((msg.format(duration, sum_waits)))

    return pages


def get_multiple_pages2(host, port, waits, show_time=True):
    """Get multiple pages."""
    start = time.perf_counter()
    pages = []
    tasks = []

    with closing(asyncio.get_event_loop()) as loop:
        for wait in waits:
            tasks.append(get_page(host, port, wait))
        pages = loop.run_until_complete(asyncio.gather(*tasks))

    duration = time.perf_counter() - start
    sum_waits = sum(waits)

    if show_time:
        msg = "It took {:4.2f} seconds for a total waiting time of {:4.2f}."
        print((msg.format(duration, sum_waits)))

    return pages


if __name__ == '__main__':

    def main():
        """Test it!"""
        if random.choice([True, False]):
            pages = get_multiple_pages(host='localhost', port='8888',waits=[1, 5, 3, 2])
            for page in pages:
                print(page)
        else:
            pages = get_multiple_pages2(host='localhost', port='8888',waits=[1, 5, 3, 2])
            for page in pages:
                print(page)

    main()

