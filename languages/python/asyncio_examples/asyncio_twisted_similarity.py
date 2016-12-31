"""
from twisted.internet import defer
from twisted.internet import reactor

def multiply(x):
    result = x * 2
    d = defer.Deferred()
    reactor.callLater(1.0, d.callback, result)
    return d

def step1(x):
    return multiply(x)

def step2(result):
    print("result: %s", result)
    reactor.stop()

d = deter.Deferred()
d.addCallback(step1)
d.addCallback(step2)
d.callback(5)

reactor.run()
"""

import asyncio

async def multiply(x):
    result = x * 2
    await asyncio.sleep(1)
    return result

async def steps(x):
    result = await multiply(x)
    print("result: %s" % result)


loop = asyncio.get_event_loop()
coro = steps(5)
loop.run_until_complete(coro)
loop.close()
