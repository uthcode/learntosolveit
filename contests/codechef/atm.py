#!/usr/bin/python

"""
Easy Contest: ATM
www.codechef.com
"""

withdraw, acc_balance = map(float, raw_input().split())
if (withdraw + 0.5) >= acc_balance:
    print '%.2f' % acc_balance
elif not (withdraw % 5 == 0):
    print '%.2f' % acc_balance
else:
    remaining = acc_balance - withdraw
    remaining -= 0.50
    print '%.2f' % remaining
