#!/usr/bin/env python3.1

import pickle

# An arbitrary collection of objects supported by pickle.

data = {
    'a': [1, 2.0, 3, 4+6j],
    'b': ("character string", b"byte string"),
    'c': set([None, True, False])
}


with open('data.pickle', 'wb') as f:
    # Pickle the 'data' dictionary using the highest protocol available
    pickle.dump(data, f, pickle.HIGHEST_PROTOCOL)


# Now read it

with open('data.pickle', 'rb') as f:
    # The protocol version used is detected automatically, so we don't have to
    # explitcitly specify it.
    data = pickle.load(f)
    print(data)
