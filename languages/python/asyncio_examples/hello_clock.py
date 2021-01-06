"""
Hello Clock

Example illustrating how to schedule two coroutines to run concurrently.
They run for ten minutes, during which the first coroutine is scheduled to run every second, while the second is scheduled to run every minute.
"""

import asyncio

async def print_every_second():
    """"Print seconds."""
    while True:
        for i in range(60):
            print((i, 's'))
            await asyncio.sleep(1)

async def print_every_minute():
    """Print Every minute."""
    for i in range(1, 10):
        await asyncio.sleep(60)
        print((i, "minute"))

loop = asyncio.get_event_loop()
loop.run_until_complete(
    asyncio.gather(print_every_second(), print_every_minute()))
loop.close()
