t = int(raw_input())
for tc in range(t):
    infix = raw_input()
    stack = []
    for c in infix:
        if c == '(':
            pass
        elif c == ')':
            exp1 = stack.pop()
            exp2 = stack.pop()
            exp3 = stack.pop()
            exp = exp3 + exp1 + exp2
            stack.append(exp)
        else:
            stack.append(c)
    print stack.pop()
