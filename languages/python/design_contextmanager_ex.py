from contextlib import contextmanager

@contextmanager
def opened(filename, mode="r"):
    f = open(filename, mode)
    try:
        yield f
    finally:
        f.close()

with opened("toss_coins.py") as f:
    for line in f:
        print line.strip()
