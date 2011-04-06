# Module 'macglob' -- version of 'glob' for the Macintosh.

# XXX At least one bug is left: a pattern like '*:' is treated
# XXX as a relative pathname (and returns as if it was ':*:').

import mac
import macpath
import fnmatch

def glob(pathname):
       if not has_magic(pathname): return [pathname]
       dirname, basename = macpath.split(pathname)
       if has_magic(dirname):
               if dirname[-1:] = ':': dirname = dirname[:-1]
               list = glob(dirname)
       else:
               list = [dirname]
       if not has_magic(basename):
               result = []
               for dirname in list:
                       if basename or macpath.isdir(dirname):
                               name = macpath.cat(dirname, basename)
                               if macpath.exists(name):
                                       result.append(name)
       else:
               result = []
               for dirname in list:
                       sublist = glob1(dirname, basename)
                       for name in sublist:
                               result.append(macpath.cat(dirname, name))
       return result

def glob1(dirname, pattern):
       if not dirname: dirname = ':'
       try:
               names = mac.listdir(dirname)
       except mac.error:
               return []
       result = []
       for name in names:
               if name[0] <> '.' or pattern[0] = '.':
                       if fnmatch.fnmatch(name, pattern): result.append(name)
       return result

def has_magic(s):
       return '*' in s or '?' in s or '[' in s
