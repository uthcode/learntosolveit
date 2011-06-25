import os

print 'popen3'

pipe_stdin, pipe_stdout, pipe_stderr = os.popen3('cat -;echo "Error Message" 1>&2')

try:
    pipe_stdin.write("Hello, World")
finally:
    pipe_stdin.close()

try:
    stdout_value = pipe_stdout.read()
finally:
    pipe_stdout.close()

try:
    stderr_value = pipe_stderr.read()
finally:
    pipe_stderr.close()

print 'STDOUT:', stdout_value
print 'STDERR:', stderr_value

