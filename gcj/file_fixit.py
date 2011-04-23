"""
Problem Statement: http://code.google.com/codejam/contest/dashboard?c=635101

This is an interesting problem, try to construct a tree of directories and then
count many of those levels exist, after removing the already existing
directories. The first thing was constructing the tree as a dict for each level
and having the key of the dict as the level number. After constructing this,
the problem is easy to solve.

"""

T = int(raw_input())
for tc in range(1,T+1):
    n_already, n_required = map(int,raw_input().split())
    already = []
    required = []
    tree = {}
    for i in range(n_already):
        already.append(raw_input())
    for i in range(n_required):
        required.append(raw_input())
    for eachpath in required:
        paths = eachpath.split('/')
        for i in range(1,len(paths)):
            dirpath = '/'.join(paths[:i+1])
            if i in tree:
                if dirpath not in tree[i]:
                    tree[i].append(dirpath)
            else:
                tree[i] = [dirpath]
    already = sorted(already,key=len)
    for each in already:
        i = each.count('/')
        if i in tree:
            if each in tree[i]:
                tree[i].remove(each)
    n = 0
    for each in tree.values():
        n += len(each)
    print 'Case #%d: %d' % (tc, n)
