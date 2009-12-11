import fcntl
import time, os

FILE = "counter.txt"

if not os.path.exists(FILE):
    # Create the counter file if it does not exist.
    file = open(FILE,'w')
    file.write('0')
    file.close()

for i in range(20):
    # Increment the counter
    file = open(FILE,"r+")
    fcntl.flock(file.fileno(), fcntl.LOCK_EX)
    counter = int(file.readline()) + 1
    file.seek(0)
    file.write(str(counter))
    file.close()
    print os.getpid(), '=>' , counter
    time.sleep(0.1)
