import asyncio

async def run_command(*args):
    # Create a subprocess
    process = await asyncio.create_subprocess_exec(
        *args,
        # stdout must be a pipe to be accessible as process.stdout
        stdout=asyncio.subprocess.PIPE)
    # Wait for the subprocess to finish
    stdout, stderr = await process.communicate()
    # return stdout
    return stdout.decode().strip()

loop = asyncio.get_event_loop()

# Gather uname and date commands

commands = asyncio.gather(
    run_command('uname'),
    run_command('date'))

# Run the commands

uname, date = loop.run_until_complete(commands)

# Print a report

print(('uname: {}, date: {}'.format(uname, date)))
loop.close()
