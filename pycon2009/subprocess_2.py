# Read Output of another command

import subprocess

print '\nread:'
proc = subprocess.Popen('echo "Hello,World"',
                        shell=True,
                        stdout=subprocess.PIPE,
                       )
stdout_value = proc.communicate()[0]
print '\tstdout:',stdout_value


# Writing to the input of a pipe:

print '\nwrite:'
proc = subprocess.Popen('cat -',
                        shell=True,
                        stdin=subprocess.PIPE,
                       )
proc.communicate('\tstdin: to stdin\n')


# Reading and Writing through PIPES as with popen2

print '\npopen2:'

proc = subprocess.Popen('cat -',
                        shell=True,
                        stdin=subprocess.PIPE,
                        stdout=subprocess.PIPE,
                       )
stdout_value = proc.communicate('through stdin to stdout')[0]
print '\tpass through:',repr(stdout_value)

