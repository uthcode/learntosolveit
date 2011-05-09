"""
0-1 divide into three parts

(1-0) / 3 = 1/3

0+1/3 = 1/3
1/3+1/3 = 2/3
2/3+1/3 = 3/3

(3/3-2/3) / 3 = 1/9

2/3+1/9 = 7/9
7/9+1/9 = 8/9
8/9+1/9 = 9/9


(1/3-0)/3 = 1/9

0+1/9 = 1/9
1/9+1/9 = 2/9
2/9+1/9 = 3/9

"""
import decimal

order = {1:(1.0/3,2.0/3),
         2:(1.0/9,2.0/9),
         3:(7.0/9,8.0/9)
        }

levels = [0,1.0/9,2.0/9,1.0/3,2.0/3,7.0/9,8.0/9,1]
T = int(raw_input())
for tc in range(1,T+1):
    print 'Case #%d:' % tc
    N = int(raw_input())
    numbers = []
    for n in range(N):
        numbers.append(decimal.Decimal(raw_input()))
    group1 = []
    group2 = []
    group3 = []
    for number in numbers:
        if ((float(number) >= (1.0/9) and float(number) <= (2.0/9)) or
              (float(number) >= (7.0/9) and float(number) <= (8.0/9))):
            print 'group2', number
            group2.append(number)
        elif (1.0/3 <= float(number) <= 2.0/3):
            print 'group1', number
            group1.append(number)
        else:
            print 'group3',number
            group3.append(number)
    group1.sort()
    group2.sort()
    group3.sort()
    result = group1 + group2 + group3
    for each in result:
        print each
