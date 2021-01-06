import subprocess
proc = subprocess.Popen(['./simple'], stdout=subprocess.PIPE,
        stderr=subprocess.PIPE)
out,err = proc.communicate()
print(out)
print(err)
