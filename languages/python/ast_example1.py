#!/usr/bin/python
#$Id$

"""
This program is directly executing it a Abstract Syntax Tree Level.
This is just doing xy*3.
"""
import ast

node = ast.Expression(ast.BinOp(
                ast.Str('xy'),
                ast.Mult(),
                ast.Num(3)))

fixed = ast.fix_missing_locations(node)

codeobj = compile(fixed, '<string>', 'eval')
print eval(codeobj)
