import subprocess
proc = subprocess.Popen(['date'],stdout=subprocess.PIPE,stderr=subprocess.PIPE)
out,err = proc.communicate()
print(out)
print(err)
