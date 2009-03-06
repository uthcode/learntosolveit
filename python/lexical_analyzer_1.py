# Write the lexical analyzer for the tokens:
# Regular Expression    Tokens  Attribute-Value
# ws                    -       -
# if                    if      -
# then                  then    -
# else                  else    -
# id                    id      pointer to table entry
# num                   num     pointer to table entry
# <                     relop   LT
# <=                    relop   LE
# =                     relop   EQ
# <>                    relop   NE
# >                     relop   GT
# >=                    relop   GE

import sys
c = sys.stdin.read(1)
ws = 0
tokens = {'ws':0,'if':0,'then':0,'else':0,'id':0,'num':0,'LT':0,'LE':0,'EQ':0,'NE':0,'GT':0,'GE':0}
digits = ['0','1','2','3','4','5','6','7','8','9']
while c:
    if c in [' ','\t']:
        tokens['ws'] = tokens['ws'] + 1
    elif c == 'i':
        c = sys.stdin.read(1)
        if c == 'f':
            tokens['if'] = tokens['if'] + 1
        else:
            while c and (c != ' ' or c != ':'):
                c = sys.stdin.read(1)
            tokens['id'] = tokens['id'] + 1
    elif c == 't':
        c = sys.stdin.read(1)
        if c == 'h':
            c = sys.stdin.read(1)
            if c == 'e':
                c = sys.stdin.read(1)
                if c == 'n':
                    tokens['then'] = tokens['then'] + 1
                else:
                    while c and (c!= ' ' or c!= ':'):
                        c = sys.stdin.read(1)
                    tokens['id'] = tokens['id'] + 1
            else:
                while c and (c!= ' ' or c != ':'):
                    c = sys.stdin.read(1)
                tokens['id'] = tokens['id'] + 1
        else:
            while c and (c != ' ' or c != ':'):
                c = sys.stdin.read(1)
            tokens['id'] = tokens['id'] + 1
    elif c == 'e':
        c = sys.stdin.read(1)
        if c == 'l':
            c = sys.stdin.read(1)
            if c == 's':
                c = sys.stdin.read(1)
                if c == 'e':
                    tokens['else'] = tokens['else'] + 1
                else:
                    while c and (c != ' ' or c != ':'):
                        c = sys.stdin.read(1)
                    tokens['id'] = tokens['id'] + 1
            else:
                while c and (c!= ' ' or c != ':'):
                    c = sys.stdin.read(1)
                tokens['id'] = tokens['id'] + 1
        else:
            while c and (c != ' ' or c != ':'):
                c = sys.stdin.read(1)
            tokens['id'] = tokens['id'] + 1
    elif c == '>':
        c = sys.stdin.read(1)
        if c == '=':
            tokens['GE'] = tokens['GE'] + 1
        else:
            tokens['GT'] = tokens['GT'] + 1
    elif c == '<':
        c = sys.stdin.read(1)
        if c == '=':
            tokens['LE'] = tokens['LE'] + 1
        elif c == '>':
            tokens['NE'] = tokens['NE'] + 1
        else:
            tokens['LT'] = tokens['LT'] + 1
    elif c == '=':
        tokens['EQ'] = tokens['EQ'] + 1
    elif c in digits:
        c = sys.stdin.read(1)
        while c in digits:
            c = sys.stdin.read(1)
        if c == '.':
            c = sys.stdin.read(1)
            while c in digits:
                c = sys.stdin.read(1)
            tokens['num'] = tokens['num'] + 1
        if c == ' ' or c == '\n' or not c:
            tokens['num'] = tokens['num'] + 1
    elif c in '\n':
        pass
    else:
        while c:
            if not c in [' ','\t',':','\n']:
                c = sys.stdin.read(1)
            else:
                tokens['id'] = tokens['id'] + 1
                break
    c = sys.stdin.read(1)

print tokens
