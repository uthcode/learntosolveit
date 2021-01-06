import time
from multiprocessing import Process, Queue

def factorial(queue, N):
    "Compute a factorial."
    # If N is a multiple of 4, this function will take much longer.
    if (N % 4) == 0:
        time.sleep(0.05 * N/4)

    # Calculate the result
    fact = 1
    for i in range(1, N+1):
        fact = fact * i

    # Put the result back into the Queue
    queue.put(fact)

if __name__ == '__main__':
    queue = Queue()

    N = 5

    p = Process(target=factorial, args=(queue, N))
    p.start()
    p.join()

    result = queue.get()

    print('Factorial', N, '=', result)
