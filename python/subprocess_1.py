import subprocess

output_with_shell_true = subprocess.Popen("/bin/date;who;fortune",shell=True).wait()
print 'True', output_with_shell_true
output_with_shell_false = subprocess.Popen("/bin/date;who;fortune",shell=True).wait()
print 'False', output_with_shell_false
