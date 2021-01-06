import asyncio

async def echo(msg):
    # Run an echo subprocess
    process = await asyncio.create_subprocess_exec(
        'cat',
        # stdin must a pipe to be accessible as a process.stdin
        stdin=asyncio.subprocess.PIPE,
        stdout=asyncio.subprocess.PIPE)
    # Write a message

    print(('Writing {!r}...'.format(msg)))
    process.stdin.write(msg.encode() + b'\n')

    # Read reply

    data = await process.stdout.readline()
    reply = data.decode().strip()

    print(("Received {!r}".format(reply)))

    # Stop the subprocess

    process.terminate()
    code = await process.wait()

    print(("Terminated with code {}".format(code)))


loop = asyncio.get_event_loop()
loop.run_until_complete(echo('hello!'))
loop.close()
