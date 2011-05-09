"""
Some of reverse thinking is required.
Find numbers between 1/3 to 2/3 and return first.
Othewise, if the number is less than 1/3, multiple the number by 3 and see if
it falls between 1/3 to 2/3. Give the index of how many times you multiply.
For upper limit do, (number - upper) * 3 and see how many times you want to do.
If it does not fall,return a very high number.

"""
import decimal
import sys

def orderit(n):
    lower = decimal.Decimal(1)/3
    upper = decimal.Decimal(2)/3
    for i in range(100):
        if lower <= n <= upper:
            return i
        elif n < lower:
            n *= 3
        else:
            n = (n - upper) * 3
    return sys.maxint

T = int(raw_input())
for tc in range(1,T+1):
    print 'Case #%d:' % tc
    N = int(raw_input())
    numbers = []
    for n in range(N):
        num = decimal.Decimal(raw_input())
        numbers.append((orderit(num),num))
    numbers.sort()
    for order,num in numbers:
        print num
