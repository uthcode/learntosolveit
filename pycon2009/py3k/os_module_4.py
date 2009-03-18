import os

pipe_stdout = os.popen('echo "hello,world"','r')

try:
    stdout_value = pipe_stdout.read()
finally:
    pipe_stdout.close()

print stdout_value,


pipe_stdin = os.popen('cat -','w')

try:
    pipe_stdin.write('hello,world\n')
finally:
    pipe_stdin.close()

