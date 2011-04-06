# Utilities used by 'Tcl' emulator.


# Many functions in this file parse specific constructs from strings.
# In order to limit the number of slice operations (the strings can
# be very large), they always receive indices into the string that
# indicate the slice of the string that should be considered.
# The return value is in general another index, pointing to the first
# character in the string beyond the recognized construct.
# Errors are reported as exceptions (TclSyntaxError, TclMatchingError).
# A few functions have multiple return values.


# For efficiency, the Tcl "tokenizing" routines used pre-compiled
# regular expressions.  This is less readable but should be much faster
# than scanning the string a character at a time.
#
# The global variables
# containing the compiled regexp's are named _foo_prog where foo is
# an indication of the function that uses them.
#
# The patterns always
# have the form <something>* so they always match at the start of the
# search buffer---maybe with the empty string.  This makes it possible
# to use the expression "_foo_prog.exec(str, i)[0][1]" to find the first
# character beyond the matched string.  Note that this may be beyond the
# end variable -- where this matters, "min(i, end)" is used.

# Constructs that cannot
# be recognized by a finite automaton (like matching braces) are scanned
# by a hybrid technique where the regular expression excludes the
# braces.
#
# Many regular expressions contain an expression that matches
# a Tcl backslash sequence as a subpart:
#      \\\\C?M?(.|\n)
#
# This is a bit hard to
# read because the backslash contained in it must be doubled twice:
# once to get past Python's backslash mechanism, once to get past that
# of regular expressions.  It uses (.|\n) to match absolutely
# *every character*, becase the MULTILINE regular expression package does
# not accept '\n' as a match for '.'.
#
# There is also a simplification in the pattern for backslashes:
# *any* single character following a backslash is escaped,
# so hex and octal
# excapes are not scanned fully.  The forms \Cx, \Mx and \CMx are
# scanned correctly, as these may hide a special character.
# (This does not invalidate the recognition of strings, although the
# match is effectuated in a different way than by the Backslash function.)

import regexp


# Exceptions raised for various error conditions.

TclAssertError = 'Tcl assert error'
TclSyntaxError = 'Tcl syntax error'
TclRuntimeError = 'Tcl runtime error'
TclMatchingError = 'Tcl matching error'


# Find a variable name.
# A variable name is either a (possiblly empty) sequence of letters,
# digits and underscores, or anything enclosed in matching braces.
# Return the index past the end of the name.

_varname_prog = regexp.compile('[a-zA-Z0-9_]*')

def FindVarName(str, i, end):
       if i < end and str[i] = '{': return BalanceBraces(str, i, end)
       i = _varname_prog.exec(str, i)[0][1]
       return min(i, end)


# Split a list into its elements.
# Return a list of elements (strings).

def SplitList(str):
       i, end = 0, len(str)
       list = []
       while 1:
               i = SkipSpaces(str, i, end)
               if i >= end: break
               j = i
               i = FindNextElement(str, i, end)
               if str[j] = '{' and str[i-1] = '}':
                       element = str[j+1:i-1]
               else:
                       element = Collapse(str[j:i])
               list.append(element)
       return list


# Find the next element from a list.

_element_prog = regexp.compile('([^ \t\n\\]+|\\\\C?M?(.|\n))*')

def FindNextElement(str, i, end):
       if i < end and str[i] = '{':
               i = BalanceBraces(str, i, end)
               if i < end and str[i] not in ' \t\n':
                       raise TclSyntaxError, 'Garbage after } in list'
               return i
       i = _element_prog.exec(str, i)[0][1]
       return min(i, end)


# Copy a string, expanding all backslash sequences.

_collapse_prog = regexp.compile('(\n|[^\\]+)*')

def Collapse(str):
       if '\\' not in str: return str
       i, end = 0, len(str)
       result = ''
       while i < end:
               j = _collapse_prog.exec(str, i)[0][1]
               j = min(j, end)
               result = result + str[i:j]
               if j >= end: break
               c = str[j]
               if c <> '\\': raise TclAssertError, 'collapse error'
               x, i = Backslash(str, j, end)
               result = result + x
       return result


# Find the next full command.
# Return a list of begin, end indices of words in the string,
# and an index pointing just after the terminating newline or
# semicolon.
# Initial spaces are skipped.
# If the command begins with '#', it is considered empty and
# characters until '\n' are skipped.

_eol_prog = regexp.compile('[^\n]*')

def FindNextCommand(str, i, end, bracketed):
       i = SkipSpaces(str, i, end)
       if i >= end: return [], end
       if str[i] = '#':
               i = _eol_prog.exec(str, i)
               i = min(i, end)
               if i < end and str[i] = '\n': i = i+1
               return [], i
       if bracketed: terminators = [';']
       else: terminators = [';', '\n']
       list = []
       while i < end:
               j = FindNextWord(str, i, end)
               word = str[i:j]
               if word in terminators:
                       i = j
                       break
               if word <> '\n': list.append(i, j)
               i = SkipSpaces(str, j, end)
       return list, i


# Find the next word of a command.
# Semicolon and newline terminate words but also count as a word
# themselves.
# The start index must point to the start of the word.

_word_prog = regexp.compile('([^ \t\n;[\\]+|\\\\C?M?(.|\n))*')

def FindNextWord(str, i, end):
       if i >= end: return end
       if str[i] in '{"':
               if str[i] = '{': i = BalanceBraces(str, i, end)
               else: i = BalanceQuotes(str, i, end)
               if i >= end or str[i] in ' \t\n;': return min(i, end)
               raise TclSyntaxError, 'Garbage after } or "'
       begin = i
       while i < end:
               i = _word_prog.exec(str, i)[0][1]
               if i >= end:
                       i = end
                       break
               c = str[i]
               if c in ' \t': break
               if c in ';\n':
                       if i = begin: i = i+1
                       break
               if c = '[': i = BalanceBrackets(str, i, end)
               else: raise TclAssertError, 'word error'
       return i


# Parse balanced brackets from str[i:end].
# str[i] must be '['.
# Returns end such that str[i:end] ends with ']'
# and contains balanced braces and brackets.

_brackets_prog = regexp.compile('([^][{\\]+|\n|\\\\C?M?(.|\n))*')

def BalanceBrackets(str, i, end):
       if i >= end or str[i] <> '[':
               raise TclAssertError, 'BalanceBrackets'
       nesting = 0
       while i < end:
               i = _brackets_prog.exec(str, i)[0][1]
               if i >= end: break
               c = str[i]
               if c = '{': i = BalanceBraces(str, i, end)
               else:
                       i = i+1
                       if c = '[': nesting = nesting + 1
                       elif c = ']':
                               nesting = nesting - 1
                               if nesting = 0: return i
                       else: raise TclAssertError, 'brackets error'
       raise TclMatchingError, 'Unmatched bracket ([)'


# Parse balanced braces from str[i:end].
# str[i] must be '{'.
# Returns end such that str[i:end] ends with '}'
# and contains balanced braces.

_braces_prog = regexp.compile('([^{}\\]+|\n|\\\\C?M?(.|\n))*')

def BalanceBraces(str, i, end):
       if i >= end or str[i] <> '{':
               raise TclAssertError, 'BalanceBraces'
       nesting = 0
       while i < end:
               i = _braces_prog.exec(str, i)[0][1]
               if i >= end: break
               c = str[i]
               i = i+1
               if c = '{': nesting = nesting + 1
               elif c = '}':
                       nesting = nesting - 1
                       if nesting = 0: return i
               else: raise TclAssertError, 'braces error'
       raise TclMatchingError, 'Unmatched brace ({)'


# Parse double quotes from str[i:end].
# str[i] must be '"'.
# Returns end such that str[i:end] ends with an unescaped '"'.

_quotes_prog = regexp.compile('([^"\\]+|\n|\\\\C?M?(.|\n))*')

def BalanceQuotes(str, i, end):
       if i >= end or str[i] <> '"':
               raise TclAssertError, 'BalanceQuotes'
       i = _quotes_prog.exec(str, i+1)[0][1]
       if i < end and str[i] = '"': return i+1
       raise TclMatchingError, 'Unmatched quote (")'


# Static data used by Backslash()

_bstab = {}
_bstab['n'] = '\n'
_bstab['r'] = '\r'
_bstab['t'] = '\t'
_bstab['b'] = '\b'
_bstab['e'] = '\033'
_bstab['\n'] = ''
for c in ' {}[]$";\\': _bstab[c] = c
del c

# Backslash interpretation.
# First character must be a backslash.
# Return a pair (<replacement string>, <end of sequence>).
# Unrecognized or incomplete backslash sequences are not errors;
# this takes only the backslash itself off the string.

def Backslash(str, i, end):
       if i >= end or str[i] <> '\\':
               raise TclAssertError, 'Backslash'
       i = i+1
       if i = end: return '\\', i
       c = str[i]
       i = i+1
       if _bstab.has_key(c): return _bstab[c], i
       if c = 'C':
               if i = end: return '\\', i-1
               c = str[i]
               i = i+1
               if c = 'M':
                       if i = end: return '\\', i-2
                       c = str[i]
                       i = i+1
                       x = ord(c) % 040 + 0200
               else:
                       x = ord(c) % 040
               return chr(x), i
       elif c = 'M':
               if i = end: return '\\', i-1
               c = str[i]
               i = i+1
               x = ord(c)
               if x < 0200: x = x + 0200
               return chr(x), i
       elif c and c in '0123456789':
               x = ord(c) - ord('0')
               end = min(end, i+2)
               while i < end:
                       c = str[i]
                       if c not in '0123456789': break
                       i = i+1
                       x = x*8 + ord(c) - ord('0')
               return ord(x), i
       else:
               # Not something that we recognize
               return '\\', i-1


# Skip over spaces and tabs (but not newlines).

_spaces_prog = regexp.compile('[ \t]*')

def SkipSpaces(str, i, end):
       i = _spaces_prog.exec(str, i)[0][1]
       return min(i, end)


# Concatenate the elements of a list with intervening spaces.

def Concat(argv):
       result = ''
       sep = ''
       for arg in argv:
               result = result + (sep + arg)
               sep = ' '
       return result


# Concatenate list elements, adding braces etc. to make them parseable
# again with SplitList.

def BuildList(argv):
       result = ''
       sep = ''
       for arg in argv:
               arg = AddBraces(arg)
               result = result + (sep + arg)
               sep = ' '
       return result


# Add braces around a string if necessary to make it parseable by SplitList.

def AddBraces(str):
       # Special case for empty string
       if str = '': return '{}'
       # See if it contains balanced braces
       res = '{' + str + '}'
       if TryNextElement(res):
               # See if it would survive unquoted
               # XXX should escape [] and $ as well???
               if TryNextElement(str) and Collapse(str) = str: return str
               # No -- return with added braces
               return res
       # Unbalanced braces.  Add backslashes before suspect characters
       res = ''
       for c in str:
               if c in '$\\[]{} ;': c = '\\' + c
               elif c = '\n': c = '\\n'
               elif c = '\t': c = '\\t'
               res = res + c
       return res


def TryNextElement(str):
       end = len(str)
       try:
               i = FindNextElement(str, 0, end)
               return i = end
       except (TclSyntaxError, TclMatchingError):
               return 0
