#!/usr/bin/env python

# Expression Convertor.

import sys

if len(sys.argv) == 2:
    expression = sys.argv[1]
else:
    sys.exit("Usage: python %s \"expression\"" % sys.argv[0])

DIGITS = ['0','1','2','3','4','5','6','7','8','9']
OPERATORS = ['+','-','*','/']
LEFT_PAREN = '('
RIGHT_PAREN = ')'
PRECEDENCE_TABLE = {'/':2,'*':2,'-':1,'+':1}
OPCODE_TABLE = {'/':'DIV','*':'MUL','-':'SUB','+':'ADD'}


# Shunting yard algorithm. Hail Dijkstra!
output_queue = []
stack = []

for token in expression:
    if token in DIGITS:
        output_queue.append(token)
    elif token in OPERATORS:
        o1 = token
        while stack and (stack[len(stack)-1]) in OPERATORS:
            o2 = stack[len(stack)-1]
            if PRECEDENCE_TABLE[o1] <= PRECEDENCE_TABLE[o2]:
                o2 = stack.pop()
                output_queue.append(o2)
            else:
                break
        stack.append(o1)
    elif token == LEFT_PAREN:
        stack.append(token)
    elif token == RIGHT_PAREN:
        while len(stack) > 0:
            stack_top = stack.pop()
            if stack_top == LEFT_PAREN:
                break
            else:
                output_queue.append(stack_top)
        else:
            print 'parens mismatch; check expression'
            sys.exit()

while len(stack) > 0:
    token = stack.pop()
    if token == LEFT_PAREN:
        print 'parens mismatch; check expression'
        sys.exit()
    elif token in OPERATORS:
        output_queue.append(token)

for op in output_queue:
    if op in DIGITS:
        print 'PUSH ' + op
    elif op in OPERATORS:
        print OPCODE_TABLE[op]
