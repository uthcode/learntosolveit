import random
import time
start = time.time()
r = random.sample(list(range(10)), 5)
for x in range(1000):
    sorted_loop = sorted(r)
    for i in sorted_loop:
        pass
print(time.time() - start)
