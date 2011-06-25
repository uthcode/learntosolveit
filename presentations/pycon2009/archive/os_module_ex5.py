import os

pipe_stdin, pipe_stdout = os.popen2('cat -')

try:
    pipe_stdin.write('hello, world!')
finally:
    pipe_stdin.close()

try:
    stdout_value = pipe_stdout.read()
finally:
    pipe_stdout.close()

print stdout_value
