# Tcl-based shell (for the Macintosh)

import TclUtil
import Tcl
from Tcl import Interpreter, TclRuntimeError
import mac
import macpath
from macpath import isfile, isdir, exists

UsageError = TclRuntimeError

class ShellInterpreter() = Interpreter():
       #
       def ResetVariables(interp):
               interp.globals['ps1'] = '$ '
               interp.globals['ps2'] = '> '
               interp.globals['home'] = mac.getcwd()
       #
       def DefineCommands(interp):
               interp.commands['cd'] = interp.CdCmd
               interp.commands['grep'] = interp.GrepCmd
               interp.commands['ls'] = interp.LsCmd
               interp.commands['mkdir'] = interp.MkdirCmd
               interp.commands['mv'] = interp.MvCmd
               interp.commands['pg'] = interp.PgCmd
               interp.commands['pwd'] = interp.PwdCmd
               interp.commands['rm'] = interp.RmCmd
               interp.commands['rmdir'] = interp.RmdirCmd
               interp.commands['sync'] = interp.SyncCmd
       #
       def Reset(interp):
               interp.ResetVariables()
               interp.DefineCommands()
       #
       def Create(interp):
               interp = Interpreter.Create(interp) # initialize base class
               interp.Reset()
               return interp
       #
       # Command-implementing functions
       #
       def CdCmd(interp, argv):
               if len(argv) > 2:
                       raise UsageError, 'usage: cd [dirname]'
               if len(argv) = 2:
                       chdirto(argv[1])
               else:
                       chdirto(interp.globals['home'])
               return ''
       #
       def GrepCmd(interp, argv):
               if len(argv) < 3:
                       raise UsageError, 'usage: grep regexp file ...'
               import regexp
               try:
                       prog = regexp.compile(argv[1])
               except regexp.error, msg:
                       raise TclRuntimeError, \
                         ('grep', argv[1], ': bad regexp :', msg)
               for file in argv[2:]:
                       grepfile(prog, file)
               return ''
       #
       def LsCmd(interp, argv):
               if len(argv) < 2:
                       lsdir(':')
               else:
                       for dirname in argv[1:]:
                               lsdir(dirname)
               return ''
       #
       def MkdirCmd(interp, argv):
               if len(argv) < 2:
                       raise UsageError, 'usage: mkdir name ...'
               for name in argv[1:]:
                       makedir(name)
               return ''
       #
       def MvCmd(interp, argv):
               if len(argv) <> 3:
                       raise UsageError, 'usage: mv src dst'
               src, dst = argv[1], argv[2]
               if not exists(src):
                       raise TclRuntimeError, \
                         ('mv', src, dst, ': source does not exist')
               if exists(dst):
                       raise TclRuntimeError, \
                         ('mv', src, dst, ': destination already exists')
               try:
                       mac.rename(src, dst)
               except mac.error, msg:
                       raise TclRuntimeError, \
                               (src, dst, ': rename failed :', msg)
               return ''
       #
       def PgCmd(interp, argv):
               if len(argv) < 2:
                       raise UsageError, 'usage: page file ...'
               for name in argv[1:]:
                       pagefile(name)
               return ''
       #
       def PwdCmd(interp, argv):
               if len(argv) > 1:
                       raise UsageError, 'usage: pwd'
               else:
                       return mac.getcwd()
       #
       def RmCmd(interp, argv):
               if len(argv) < 2:
                       raise UsageError, 'usage: rm file ...'
               for name in argv[1:]:
                       remove(name)
               return ''
       #
       def RmdirCmd(interp, argv):
               if len(argv) < 2:
                       raise UsageError, 'usage: rmdir dir ...'
               for name in argv[1:]:
                       rmdir(name)
               return ''
       #
       def SyncCmd(interp, argv):
               if len(argv) > 1:
                       raise UsageError, 'usage: sync'
               try:
                       mac.sync()
               except mac.error, msg:
                       raise TclRuntimeError, ('sync failed :', msg)
       #

def chdirto(dirname):
       try:
               mac.chdir(dirname)
       except mac.error, msg:
               raise TclRuntimeError, (dirname, ': chdir failed :', msg)

def grepfile(prog, file):
       try:
               fp = open(file, 'r')
       except RuntimeError, msg:
               raise TclRuntimeError, (file, ': open failed :', msg)
       lineno = 0
       while 1:
               line = fp.readline()
               if not line: break
               lineno = lineno+1
               if prog.exec(line):
                       print file+'('+`lineno`+'):', line,

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
               if isdir(macpath.cat(dirname, name)):
                       names[i] = ':' + name + ':'
       columnize(names)

def makedir(name):
       if exists(name):
               print name, ': already exists'
               return
       try:
               mac.mkdir(name, 0777)
       except mac.error, msg:
               raise TclRuntimeError, (name, ': mkdir failed :', msg)

def pagefile(name):
       import string
       if not isfile(name):
               print name, ': no such file'
               return
       LINES = 24 - 1
       # For THINK C 3.0, make the path absolute:
       # if not macpath.isabs(name):
       #       name = macpath.cat(mac.getcwd(), name)
       try:
               fp = open(name, 'r')
       except RuntimeError, msg:
               raise TclRuntimeError, (name, ': open failed :', msg)
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

def remove(name):
       if not isfile(name):
               print name, ': no such file'
               return
       try:
               mac.unlink(name)
       except mac.error, msg:
               raise TclRuntimeError, (name, ': unlink failed :', msg)

def rmdir(name):
       if not isdir(name):
               raise TclRuntimeError, (name, ': no such directory')
       try:
               mac.rmdir(name)
       except mac.error, msg:
               raise TclRuntimeError, (name, ': rmdir failed :', msg)

def printlist(list):
       for word in list:
               print word,

def columnize(list):
       import string
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

the_interpreter = ShellInterpreter().Create()

def main():
       Tcl.MainLoop(the_interpreter)
