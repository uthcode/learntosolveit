import glob

print 'Named explicitly:'
for name in glob.glob('dir/subdir/*'):
    print '\t', name

print 'Named with wildcard'
for name in glob.glob('dir/*/*'):
    print '\t', name
