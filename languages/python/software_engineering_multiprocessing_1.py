import multiprocessing
import subprocess

def calculate(value):
    return value * 10

if __name__ == '__main__':
    pool = multiprocessing.Pool(None)
    tasks = list(range(10000))
    results = []
    r = pool.map_async(calculate, tasks, callback=results.append)
    r.wait() # Wait on the results
    print(results)
