# An emulator for John Ousterhout's 'Tcl' language in Python (wow!).
# Currently only the most basic commands are implemented.
#
# Design choices:
#
# - Names used for functions are not exactly those used by C Tcl.
#   In Python, names without 'Tcl_' prefix are acceptable because
#   names are less global than in C (and often they are prefixed
#   with a module name anyway).  Parameter conventions also differ.
#
# - The Tcl Interpreter type is implemented using a Python class.
#   Almost all functions with an Interpreter as first parameter are
#   methods of this class.
#   Applications can create derived classes to add additional commands
#   or to override specific internal functions.
#
# - Tcl errors are mapped to Python exceptions.
#   (I bet Ousterhout would have done the same in a language with
#   a proper exception mechanism).
#
# - Tcl expressions are evaluated by Python's built-in function eval().
#   This makes Python Tcl scripts incompatible with C Tcl scripts,
#   but is the only sensible solution for a quick-and-dirty version.
#   It also makes an escape to Python possible.
#
# - The Backslash function interprets \<newline>, since it
#   can return a string instead of a character.


from TclUtil import *


# Exceptions used to signify 'break' and 'continue'

TclBreak = 'TclBreak'
TclContinue = 'TclContinue'
TclReturn = 'TclReturn'


class CmdBuf():
       #
       def Create(buffer):
               buffer.string = ''
               return buffer
       #
       def Assemble(buffer, str):
               buffer.string = buffer.string + str
               if buffer.string[-1:] = '\n':
                       i, end = 0, len(buffer.string)
                       try:
                               while i < end:
                                       list, i = FindNextCommand( \
                                               buffer.string, i, end, 0)
                       except TclMatchingError:
                               return ''
                       except TclSyntaxError:
                               pass # Let Eval() return the error
                       ret = buffer.string
                       buffer.string = ''
                       return ret
               else:
                       return ''


class _Frame():
       def Create(frame):
               frame.locals = {}
               return frame

class _Proc():
       #
       def Create(proc, (interp, args, body)):
               proc.interp = interp
               proc.args = SplitList(args)     # Do this once here
               proc.body = body
               return proc
       #
       def Call(proc, argv):
               if len(argv) <> len(proc.args)+1:
                       raise TclRuntimeError, \
                               'wrong # args to proc "' + \
                               argv[0] + '"'
               # XXX No defaults or variable length 'args' yet
               frame = _Frame().Create()
               for i in range(len(proc.args)):
                       frame.locals[proc.args[i]] = argv[i+1]
               proc.interp.stack.append(frame)
               try:
                       value = proc.interp.Eval(proc.body)
               except TclReturn, value:
                       pass
               del proc.interp.stack[-1:]
               return value


import regexp
_expand_prog = regexp.compile('([^[$\\]+|\n)*')
del regexp

class Interpreter():
       #
       def Create(interp):
               interp.globals = {}
               interp.commands = {}
               interp.stack = []
               interp.commands['break'] = interp.BreakCmd
               interp.commands['concat'] = interp.ConcatCmd
               interp.commands['continue'] = interp.ContinueCmd
               interp.commands['echo'] = interp.EchoCmd
               interp.commands['eval'] = interp.EvalCmd
               interp.commands['expr'] = interp.ExprCmd
               interp.commands['for'] = interp.ForCmd
               interp.commands['glob'] = interp.GlobCmd
               interp.commands['global'] = interp.GlobalCmd
               interp.commands['if'] = interp.IfCmd
               interp.commands['index'] = interp.IndexCmd
               interp.commands['list'] = interp.ListCmd
               interp.commands['proc'] = interp.ProcCmd
               interp.commands['rename'] = interp.RenameCmd
               interp.commands['return'] = interp.ReturnCmd
               interp.commands['set'] = interp.SetCmd
               return interp
       #
       def Delete(interp):
               #
               # Only break circular references here;
               # most things will be garbage-collected.
               #
               for name in interp.commands.keys():
                       del interp.commands[name]
       #
       def CreateCommand(interp, (name, proc)):
               interp.commands[name] = proc
       #
       def DeleteCommand(interp, (name)):
               del interp.commands[name]
       #
       # Local variables are maintained on the stack.
       # A local variable with value "None" is a dummy
       # meaning that the corresponding global variable
       # should be used.
       #
       def GetVar(interp, varName):
               dict = interp.globals
               if interp.stack:
                       d = interp.stack[-1:][0].locals
                       if d.has_key(varName) and d[varName] = None:
                               pass
                       else:
                               dict = d
               if not dict.has_key(varName):
                       raise TclRuntimeError, \
                               'Variable "' + varName + '" not found'
               return dict[varName]
       #
       def SetVar(interp, (varName, newValue)):
               dict = interp.globals
               if interp.stack:
                       d = interp.stack[-1:][0].locals
                       if d.has_key(varName) and d[varName] = None:
                               pass
                       else:
                               dict = d
               dict[varName] = newValue
       #
       def Expand(interp, (str, i, end)):
               if end <= i: return ''
               if str[i] = '{' and str[end-1] = '}':
                       return str[i+1:end-1]
               if str[i] = '"' and str[end-1] = '"':
                       i, end = i+1, end-1
               result = ''
               while i < end:
                       c = str[i]
                       if c = '\\':
                               x, i = Backslash(str, i, end)
                               result = result + x
                       elif c = '[':
                               j = BalanceBrackets(str, i, end)
                               x = interp.EvalBasic(str, i+1, j-1, 1)
                               result = result + x
                               i = j
                       elif c = '$':
                               i = i+1
                               j = FindVarName(str, i, end)
                               name = str[i:j]
                               i = j
                               if not name:
                                       result = result + '$'
                               else:
                                       if name[:1] = '{' and name[-1:] = '}':
                                               name = name[1:-1]
                                       result = result + interp.GetVar(name)
                       else:
                               j = _expand_prog.exec(str, i)
                               j = min(j, end)
                               result = result + str[i:j]
                               i = j
               return result
       #
       def EvalBasic(interp, (str, i, end, bracketed)):
               result = ''
               while i < end:
                       indexargv, i = FindNextCommand( \
                                       str, i, end, bracketed)
                       if indexargv:
                               argv = []
                               for x, y in indexargv:
                                       arg = interp.Expand(str, x, y)
                                       argv.append(arg)
                               name = argv[0]
                               if not interp.commands.has_key(name):
                                       raise TclRuntimeError, \
                                               'Command "' + name + \
                                               '" not found'
                               result = interp.commands[name](argv)
               return result
       #
       def Eval(interp, str):
               return interp.EvalBasic(str, 0, len(str), 0)
       #
       def ExprBasic(interp, (str, begin, end)):
               expr = interp.Expand(str, begin, end)
               i = SkipSpaces(expr, 0, len(expr))
               expr = expr[i:]
               try:
                       return eval(expr, {})
               except (NameError, TypeError, RuntimeError, EOFError), msg:
                       import sys
                       raise TclRuntimeError, sys.exc_type + ': ' + msg
       #
       def Expr(interp, str):
               return interp.ExprBasic(str, 0, len(str))
       #
       # The rest are command implementations
       #
       def BreakCmd(interp, argv):
               if len(argv) <> 1:
                       raise TclRuntimeError, 'usage: break'
               raise TclBreak
       #
       def ConcatCmd(interp, argv):
               if len(argv) < 2:
                       raise TclRuntimeError, 'usage: concat arg ...'
               return Concat(argv[1:])
       #
       def ContinueCmd(interp, argv):
               if len(argv) <> 1:
                       raise TclRuntimeError, 'usage: continue'
               raise TclContinue
       #
       def EchoCmd(interp, argv):
               for arg in argv[1:]: print arg,
               print
               return ''
       #
       def EvalCmd(interp, argv):
               if len(argv) < 2:
                       raise TclRuntimeError, 'usage: eval arg [arg ...]'
               str = Concat(argv[1:])
               return interp.Eval(str)
       #
       def ExprCmd(interp, argv):
               if len(argv) <> 2:
                       raise TclRuntimeError, 'usage: expr expression'
               expr = argv[1]
               result = interp.Expr(expr)
               if type(result) <> type(''): result = `result`
               return result
       #
       def ForCmd(interp, argv):
               if len(argv) <> 5:
                       raise TclRuntimeError, \
                               'usage: for start test next body'
               x = interp.Eval(argv[1])
               while interp.Expr(argv[2]):
                       try:
                               x = interp.Eval(argv[4])
                       except TclBreak:
                               break
                       except TclContinue:
                               pass
                       x = interp.Eval(argv[3])
               return ''
       #
       def GlobCmd(interp, argv):
               import macglob
               if len(argv) < 2:
                       raise TclRuntimeError, 'usage: glob pattern ...'
               list = []
               for pat in argv[1:]:
                       list = list + macglob.glob(pat)
               if not list:
                       raise TclRuntimeError, 'no match for glob pattern(s)'
               return BuildList(list)
       #
       def GlobalCmd(interp, argv):
               if len(argv) < 2:
                       raise TclRuntimeError, 'usage: global varname ...'
               if not interp.stack:
                       raise TclRuntimeError, 'global used outside proc'
               dict = interp.stack[-1:][0].locals
               for name in argv[1:]:
                       dict[name] = None
               return ''
       #
       def IfCmd(interp, argv):
               argv = argv[:]
               if len(argv) > 2 and argv[2] = 'then': del argv[2]
               if len(argv) > 3 and argv[3] = 'else': del argv[3]
               if not 3 <= len(argv) <= 4:
                       raise TclRuntimeError, \
                        'usage: if test [then] trueBody [else] falseBody'
               if interp.Expr(argv[1]):
                       return interp.Eval(argv[2])
               if len(argv) > 3:
                       return interp.Eval(argv[3])
               return ''
       #
       def IndexCmd(interp, argv):
               if len(argv) <> 3:
                       raise TclRuntimeError, 'usage: index value index'
               import string
               try:
                       index = string.atoi(argv[2])
                       if index < 0: raise string.atoi_error
               except string.atoi_error:
                       raise TclRuntimeError, 'bad index: ' + argv[2]
               list = SplitList(argv[1])
               if index >= len(list): return ''
               return list[index]
       #
       def ListCmd(interp, argv):
               if len(argv) < 2:
                       raise TclRuntimeError, 'usage: list arg ...'
               return BuildList(argv[1:])
       #
       def ProcCmd(interp, argv):
               if len(argv) <> 4:
                       raise TclRuntimeError, 'usage: proc name args body'
               x = _Proc().Create(interp, argv[2], argv[3])
               interp.CreateCommand(argv[1], x.Call)
               return ''
       #
       def RenameCmd(interp, argv):
               if len(argv) <> 3:
                       raise TclRuntimeError, 'usage: rename oldName newName'
               oldName, newName = argv[1], argv[2]
               if not interp.commands.has_key(oldName):
                       raise TclRuntimeError, \
                               'command "' + oldName + '" not found'
               if newName: interp.commands[newName] = interp.commands[oldName]
               del interp.commands[oldName]
               return ''
       #
       def ReturnCmd(interp, argv):
               if not 1 <= len(argv) <= 2:
                       raise TclRuntimeError, 'usage: return [arg]'
               if len(argv) = 1: raise TclReturn, ''
               raise TclReturn, argv[1]
       #
       def SetCmd(interp, argv):
               n = len(argv)
               if not 2 <= n <= 3:
                       raise TclRuntimeError, 'usage: set varname [newvalue]'
               if n = 2: return interp.GetVar(argv[1])
               interp.SetVar(argv[1], argv[2])
               return ''


# The rest are just demos:

def MainLoop(interp):
       buffer = CmdBuf().Create()
       if not interp.globals.has_key('ps1'): interp.globals['ps1'] = '% '
       if not interp.globals.has_key('ps2'): interp.globals['ps2'] = ''
       psname = 'ps1'
       while 1:
               try:
                       line = raw_input(interp.globals[psname])
               except (EOFError, KeyboardInterrupt):
                       print
                       break
               line = buffer.Assemble(line + '\n')
               if not line:
                       psname = 'ps2'
               else:
                       psname = 'ps1'
                       try:
                               x = interp.Eval(line)
                               if x <> '': print 'Result:', `x`
                       except (TclRuntimeError, TclSyntaxError, \
                               TclMatchingError), msg:
                               print 'Error:', msg
                       except (TclBreak, TclContinue):
                               print 'Error: break or continue outside loop'
                       except TclReturn, value:
                               # Return outside proc returns to main loop
                               if value: print value


the_interpreter = Interpreter().Create()

def main():
       MainLoop(the_interpreter)


# XXX To do:
# for proc: "args" and default arguments
# More commands:
# case
# uplevel
# info
# string
# list operations
# error, catch
# print
# scan, format
# source
# history?
# others?
