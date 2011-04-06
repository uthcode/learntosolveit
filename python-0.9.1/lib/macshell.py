# Macintosh 'shell'
# vi:set tabsize=4:

# XXX string quoting in arguments
# XXX directory stack
# XXX $macros?
# XXX ^C during any command
# XXX 'sh' builtin command?
# XXX why does open require absolute path? (need to fix chdir.c)


import mac

import macpath
import string
import glob
from macpath import isfile, isdir, exists
import TclUtil # For splitting/quoting mechanisms

class Struct(): pass
G = Struct()

def reset():
       G.debug = 0
       G.ps1 = '$ '
       G.homedir = mac.getcwd()
       G.commands = mkcmdtab()
       G.aliases = {}

def mkcmdtab():
       tab = {}
       tab['alias'] = do_alias
       tab['cd'] = do_cd
       tab['debug'] = do_debug
       tab['grep'] = do_grep
       tab['help'] = do_help
       tab['ls'] = do_ls
       tab['mkdir'] = do_mkdir
       tab['mv'] = do_mv
       tab['page'] = do_page
       tab['pwd'] = do_pwd
       tab['reset'] = do_reset
       tab['rm'] = do_rm
       tab['rmdir'] = do_rmdir
       tab['sync'] = do_sync
       tab['unalias'] = do_unalias
       return tab

def main():
       while 1:
               try:
                       line = raw_input(G.ps1)
               except EOFError:
                       print '[EOF]'
                       break
               except KeyboardInterrupt:
                       print '[Intr]'
                       line = ''
               if G.debug:
                       print 'line:', `line`
               words = TclUtil.SplitList(line)
               if G.debug:
                       print 'words:', words
               if words and words[0][0] <> '#':
                       run(words)

def run(words):
       expandaliases(words)
       cmd = words[0]
       args = words[1:]
       if G.commands.has_key(cmd):
               if args:
                       try:
                               args = expandgloblist(args)
                       except glob_error, msg:
                               print cmd, ': glob error :', msg
                               return
               G.commands[cmd](args)
               return
       if hasglobchar(cmd):
               if args:
                       print cmd, ': cannot glob pattern with arguments'
                       return
               try:
                       words = expandglobword(cmd)
               except glob_error, msg:
                       print cmd, ': glob error :', msg
                       return
               if len(words) > 1:
                       columnize(words)
                       return
               cmd = words[0]
               print cmd
       if isfile(cmd):
               if args:
                       print cmd, ': file command expects no arguments'
                       return
               do_page([cmd])
       elif isdir(cmd):
               if args:
                       print cmd, ': directory command expects no arguments'
                       return
               do_cd([cmd])
       else:
               print cmd, ': no such command, file or directory'

glob_error = 'glob error'

def expandgloblist(words):
       res = []
       for word in words:
               if hasglobchar(word):
                       res = res + expandglobword(word)
               else:
                       res.append(word)
       return res

def expandglobword(word):
       names = glob.globlist(mac.listdir(':'), word)
       if not names: raise glob_error, 'no match for pattern ' + word
       return names

def hasglobchar(word):
       return '*' in word or '?' in word

def expandaliases(words):
       seen = []
       cmd = words[0]
       while cmd not in seen and G.aliases.has_key(cmd):
               seen.append(cmd)
               words[:1] = G.aliases[cmd]
               cmd = words[0]

def do_alias(args):
       if not args:
               listaliases()
       elif len(args) = 1:
               listalias(args[0])
       else:
               defalias(args[0], args[1:])

def listaliases():
       names = G.aliases.keys()
       names.sort()
       for name in names: listalias(name)

def listalias(name):
       if not G.aliases.has_key(name):
               print name, ': no such alias'
               return
       print 'alias', name,
       printlist(G.aliases[name])
       print

def defalias(name, expansion):
       G.aliases[name] = expansion

def do_cd(args):
       if len(args) > 1:
               print 'usage: cd [dirname]'
       elif args:
               chdirto(args[0])
       else:
               chdirto(G.homedir)

def chdirto(dirname):
       try:
               mac.chdir(dirname)
       except mac.error, msg:
               print dirname, ':', msg
               return

def do_debug(args):
       G.debug = (not G.debug)

def do_grep(args):
       if len(args) < 2:
               print 'usage: grep regexp file ...'
               return
       import regexp
       try:
               prog = regexp.compile(args[0])
       except regexp.error, msg:
               print 'regexp.compile error for', args[0], ':', msg
               return
       for file in args[1:]:
               grepfile(prog, file)

def grepfile(prog, file):
       try:
               fp = open(file, 'r')
       except RuntimeError, msg:
               print file, ': cannot open :', msg
               return
       lineno = 0
       while 1:
               line = fp.readline()
               if not line: break
               lineno = lineno+1
               if prog.exec(line):
                       print file+'('+`lineno`+'):', line,

def do_help(args):
       if args:
               print 'usage: help'
               return
       names = G.commands.keys()
       names.sort()
       columnize(names)

def do_ls(args):
       if not args:
               lsdir(':')
       else:
               for dirname in args:
                       lsdir(dirname)

def lsdir(dirname):
       if not isdir(dirname):
               print dirname, ': no such directory'
               return
       names = mac.listdir(dirname)
       lsfiles(names, dirname)

def lsfiles(names, dirname):
       names = names[:] # Make a copy so we can modify it
       for i in range(len(names)):
               name = names[i]
               if G.debug: print i, name
               if isdir(macpath.cat(dirname, name)):
                       names[i] = ':' + name + ':'
       columnize(names)

def columnize(list):
       COLUMNS = 80-1
       n = len(list)
       colwidth = maxwidth(list)
       ncols = (COLUMNS + 1) / (colwidth + 1)
       if ncols < 1: ncols = 1
       nrows = (n + ncols - 1) / ncols
       for irow in range(nrows):
               line = ''
               for icol in range(ncols):
                       i = irow + nrows*icol
                       if 0 <= i < n:
                               word = list[i]
                               if i+nrows < n:
                                       word = string.ljust(word, colwidth)
                               if icol > 0:
                                       word = ' ' + word
                               line = line + word
               print line

def maxwidth(list):
       width = 0
       for word in list:
               if len(word) > width:
                       width = len(word)
       return width

def do_mv(args):
       if len(args) <> 2:
               print 'usage: mv src dst'
               return
       src, dst = args[0], args[1]
       if not exists(src):
               print src, ': source does not exist'
               return
       if exists(dst):
               print src, ': destination already exists'
               return
       try:
               mac.rename(src, dst)
       except mac.error, msg:
               print src, dst, ': rename failed:', msg

def do_mkdir(args):
       if not args:
               print 'usage: mkdir name ...'
               return
       for name in args:
               makedir(name)

def makedir(name):
       if exists(name):
               print name, ': already exists'
               return
       try:
               mac.mkdir(name, 0777)
       except mac.error, msg:
               print name, ': mkdir failed:', msg

def do_page(args):
       if not args:
               print 'usage: page file ...'
               return
       for name in args:
               pagefile(name)

def pagefile(name):
       if not isfile(name):
               print name, ': no such file'
               return
       LINES = 24 - 1
       # For THINK C 3.0, make the path absolute:
       # if not macpath.isabs(name):
       #       name = macpath.cat(mac.getcwd(), name)
       try:
               fp = open(name, 'r')
       except:
               print name, ': cannot open'
               return
       line = fp.readline()
       while line:
               for i in range(LINES):
                       print line,
                       line = fp.readline()
                       if not line: break
               if line:
                       try:
                               more = raw_input('[more]')
                       except (EOFError, KeyboardInterrupt):
                               print
                               break
                       if string.strip(more)[:1] in ('q', 'Q'):
                               break

def do_pwd(args):
       if args:
               print 'usage: pwd'
       else:
               print mac.getcwd()

def do_reset(args):
       if args:
               print 'usage: reset'
       else:
               reset()

def do_rm(args):
       if not args:
               print 'usage: rm file ...'
               return
       for name in args:
               remove(name)

def remove(name):
       if not isfile(name):
               print name, ': no such file'
               return
       try:
               mac.unlink(name)
       except mac.error, msg:
               print name, ': unlink failed:', msg

def do_rmdir(args):
       if not args:
               print 'usage: rmdir dir ...'
               return
       for name in args:
               rmdir(name)

def rmdir(name):
       if not isdir(name):
               print name, ': no such directory'
               return
       try:
               mac.rmdir(name)
       except mac.error, msg:
               print name, ': rmdir failed:', msg

def do_sync(args):
       if args:
               print 'usage: sync'
               return
       try:
               mac.sync()
       except mac.error, msg:
               print 'sync failed:', msg

def do_unalias(args):
       if not args:
               print 'usage: unalias name ...'
               return
       for name in args:
               unalias(name)

def unalias(name):
       if not G.aliases.has_key(name):
               print name, ': no such alias'
               return
       del G.aliases[name]

def printlist(list):
       for word in list:
               print word,

reset()
main()
