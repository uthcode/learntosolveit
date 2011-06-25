import os
from urllib import pathname2url, url2pathname

print '==Default=='

path = '/a/b/c'

print 'Original:', path
print 'URL:', pathname2url(path)
print 'Path:', url2pathname('/d/e/f')


from nturl2path import pathname2url, url2pathname

print '== Windows without a Drive Letter =='
path = path.replace('/','\\')
print 'Original:', path
print 'URL:', pathname2url(path)
print 'Path:', url2pathname('/d/e/f')

print '== Windows URL with a Drive Letter =='
path = 'C:\\' + path.replace('/','\\')

print 'Original:', path
print 'URL     :', pathname2url(path)
print 'Path    :', url2pathname('/d/e/f') 
