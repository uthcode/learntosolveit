import random
import time
start = time.time()
r = random.sample(list(range(10)), 5)
for x in range(1000):
    for i in sorted(r):
        pass
print(time.time() - start)
