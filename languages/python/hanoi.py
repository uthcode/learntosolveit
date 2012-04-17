disks = 3
from_tower = 'A'
to_tower = 'C'
using_tower = 'B'

def hanoi(n, from_tower, to_tower, using_tower):
    if n > 0:
        hanoi(n-1, from_tower, using_tower, to_tower)
        print 'move disk from ', from_tower, ' to ', to_tower
        hanoi(n-1, using_tower, to_tower, from_tower)

hanoi(disks, from_tower, to_tower, using_tower)
