import asyncio
import random

async def produce(queue, n):
    for x in range(1, n+1):
        # produce an item
        print('producing {}/{}'.format(x, n))
        # simulate i/o operation using sleep
        await asyncio.sleep(random.random())
        item = str(x)
        # put the item in the queue
        await queue.put(item)


async def consume(queue):
    while True:
        # wait for an item from the producer
        item = await queue.get()
        if item is None:
            # producer emits None to indicate that it is done
            break

        # process the item

        print("consuming item {}...".format(item))
        # simulate the i/o operation using sleep
        await asyncio.sleep(random.random())

loop = asyncio.get_event_loop()
queue = asyncio.Queue(loop=loop)
producer_coro = produce(queue, 10)
consumer_coro = consume(queue)

loop.run_until_complete(asyncio.gather(producer_coro, consumer_coro))
loop.close()
