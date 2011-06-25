import os

print 'popen2, cmd as sequence:'

pipe_stdin, pipe_stdout = os.popen2(['cat','-'])

try:
    pipe_stdin.write('through stdin to stdout')
finally:
    pipe_stdin.close()

try:
    stdout_value = pipe_stdout.read()
finally:
    pipe_stdout.close()

print stdout_value
