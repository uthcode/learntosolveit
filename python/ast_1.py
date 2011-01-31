import ast

node = ast.Expression(ast.BinOp(
                ast.Str('xy'),
                ast.Mult(),
                ast.Num(3)))

fixed = ast.fix_missing_locations(node)

codeobj = compile(fixed, '<string>', 'eval')
print eval(codeobj)
