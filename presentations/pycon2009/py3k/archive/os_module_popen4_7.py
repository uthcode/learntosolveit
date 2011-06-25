import os

pipe_stdin, pipe_stdout_and_stderr = os.popen4('cat -;echo "Hello, Rats!" 1>&2')

try:
    pipe_stdin.write("Hello, World!")
finally:
    pipe_stdin.close()

try:
    stdout_value = pipe_stdout_and_stderr.read()
finally:
    pipe_stdout_and_stderr.close()

print 'Combined STDOUT and STDERR:', stdout_value

