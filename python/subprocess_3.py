import subprocess
import os
ret_value= subprocess.Popen(['find','-name','*.py']).wait()
print ret_value
ret_value = os.system('find -name "*.py"')
print ret_value
