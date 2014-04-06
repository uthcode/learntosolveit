>>> import random
>>> random.sample(range(10), 5)
[7, 6, 3, 5, 1]
>>> all(a < b for a, b in zip(_,_[1:]))
False
>>>
