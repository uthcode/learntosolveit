"""
Problem Statement:  http://code.google.com/codejam/contest/dashboard?c=189252

This problem has a misleading statement, which is designed for misleading the
solvers. This one - "ab2ac999", they could have meant "31536000" in base 10, No
where do we ever have to require to find this out in order to **solve** the
problem.

The problem is looking for *shortest* possible time. And not confuse yourself
with human bases, like base 16, base 10. It is easy to get deviated into that
path.

Instead, just create a minimal base dictionary which is required along with
values and find the minimal value like you do for any case. One caveat is that
number do not start with 0, so don't assign the first digit to 0, instead
assign the second digit to 0 and first digit to 1, as it is next minimal.

Another learning is, it much easier to understand the logic and build the
solution than learning from the solution. # I had solved this during the
contest, but when I wanted to solve this again, I got deviated and had a hard
time trying to understand from my own solution. If I just focus on logic of the
solution, I would be much faster.
"""
T = int(raw_input())
for tc in range(1,T+1):
    aliennumber = raw_input()
    base_system_length = len(set(aliennumber))
    if base_system_length == 1:
        base_system_length = 2 # It may not be unary, instead our sample was 1
    base_values = range(base_system_length)
    # But we don't want to assign the first number as 0, because the numbers
    # don't start with 0.
    base_values[0],base_values[1] = base_values[1],base_values[0]
    base_system_table = {}
    for char in aliennumber:
        if not char in base_system_table:
            base_system_table[char] = base_values.pop(0)

    # Now, convert the symbol to value
    value = 0
    aliennumber = aliennumber[::-1] # reverse it as we calcuate from RHS to LHS
    for index, char in enumerate(aliennumber):
        value += base_system_table[char] * pow(base_system_length,index)
    print 'Case #%d: %d' % (tc, value)
