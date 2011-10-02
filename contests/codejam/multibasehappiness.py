#!/usr/bin/python2.6

table = dict() # This stores the already checked happy (number, base). This is
               # to avoid the infinite loop.

def happynumber(number, base):
    if number == 1:
        return True
    if (number, base) in table:
        return table[(number,base)]

    sum = 0
    i = number
    while i:
        sum += (i%base) * (i%base)
        i //= base
    
    table[(number,base)] = False
    recursed_value = happynumber(sum, base)
    table[(number,base)] = recursed_value
    return recursed_value

def main():
    cases = int(raw_input())
    for each_case in range(cases):
        bases = map(int, raw_input().split())
        testnum = 2
        while True:
            for base in bases:
                if not happynumber(testnum, base):
                    break
            else:
                print 'Case #%d: %d' % (int(each_case)+1, testnum)
                break
            testnum += 1
    

if __name__ == '__main__':
    main()
