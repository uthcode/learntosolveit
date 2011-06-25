import os

print 'Initial value:', os.environ.get('TESTVAR',None)
print 'Child Process:', os.system('echo $TESTVAR')
print


os.environ['TESTVAR'] = 'THIS VALUE HAS CHANGED.'

print 'Changed Value:', os.environ['TESTVAR']
print 'Child Process:', os.system('echo $TESTVAR')
print


del os.environ['TESTVAR']

print 'Removed Value:', os.environ.get('TESTVAR', None)
print 'Child Process:', os.system('echo $TESTVAR')
