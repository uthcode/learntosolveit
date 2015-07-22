from string import ascii_lowercase
from itertools import combinations

HEADER = "whatever\n"

def splitter(chunksize, source, outputprefix):
    input = open(source)
    counter = 0
    for suffix in (''.join(pair) for pair in combinations(ascii_lowercase, 2)):
        with open(outputprefix + suffix, 'w') as output:
            chunk = input.read(chunksize)
            if not chunk.endswith('\n'):
                lastln = chunk.rfind('\n')
                chunksize = chunksize - lastsize
            output.write(HEADER)
            output.write(chunk)
            if len(chunk) < chunksize:
               return

splitter(15,'data.big','foo')
