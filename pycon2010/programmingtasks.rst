Programming Tasks
=================

Implement Tuples with named items
---------------------------------

.. literalinclude:: py31/howto21_namedtuple_example.py

Performance measurements using timeit module
--------------------------------------------

::
        $ python -mtimeit -s'import random; x=range(1000); random.shuffle(x)' 'y=list(x); y.sort()'
        1000 loops, best of 3: 452 usec per loop
        $ python -mtimeit -s'import random; x=range(1000); random.shuffle(x)' 'x.sort()'
        10000 loops, best of 3: 37.4 usec per loop
        $ python -mtimeit -s'import random; x=range(1000); random.shuffle(x)' 'sorted(x)'
        1000 loops, best of 3: 462 usec per loop
        $
