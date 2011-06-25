import time
import subprocess

t_beginning = time.time()
seconds_passed = 0
timeout = 5
p = subprocess.Popen(['sleep', '10'],stdout=subprocess.PIPE, stderr=subprocess.PIPE)

class TimeoutError(Exception):
    pass

while True:
    print p.poll()
    if p.poll() is not None:
        print p.poll()
        break
    seconds_passed = time.time() - t_beginning
    if timeout and seconds_passed > timeout:
        time.sleep(2)
        print p.poll()
        p.terminate()
        raise TimeoutError(timeout)
    time.sleep(0.1)
