# Program which converts the given input integer to roman numeral.
# Limitation: Program converts the integer numbers uptil the value of 1000
# (Roman Numeral: D)
# Problem: P2.1 - Implement a translator from integers to roman numeral based
# on the syntax directed translation scheme developed in Exercise 2.9
# Chapter 2 - A Simple One-Pass Compiler. Compilers, Principles, Techniques
# and Tools.


roman_dict = {1:'I',5:'V',10:'X',50:'L',100:'C',500:'D',1000:'M'}

def sep_num(n):
    num = []
    if n/100:
        hundreds = (n/100) * 100
        num.append(hundreds)
        n = n%100
        tens = (n/10) * 10
        if tens:
            num.append(tens)
        ones = n%10
        if ones:
            num.append(ones)
    elif n/10:
        tens = (n/10) * 10
        num.append(tens)
        ones = n%10
        if ones:
            num.append(ones)
    else:
        ones = n
        num.append(ones)
    return num

def get_roman(n):
    rnos = []
    if n in roman_dict:
        rnos.append(n)
        return rnos
    else:
        if 1 < n < 5:
            base,factor = 1,1
            rnos.append(base)
            result = n - base
            while result > 0:
                rnos.append(factor)
                result = result - factor
            if rnos.count(factor) > 3:
                for n in rnos[:]:
                    rnos.remove(n)
                indices = list(roman_dict.keys())
                indices.sort()
                prev_base = base
                base_index = indices.index(base) + 1
                base = indices[base_index]
                rnos.append(prev_base)
                rnos.append(base)
            return rnos
        elif 5 < n < 10:
            base,factor = 5,1
            rnos.append(base)
            result = n - base
            while result > 0:
                rnos.append(factor)
                result = result - factor
            if rnos.count(factor) > 3:
                for n in rnos[:]:
                    rnos.remove(n)
                indices = list(roman_dict.keys())
                indices.sort()
                prev_base_index = indices.index(base) - 1
                prev_base = indices[prev_base_index]
                base_index = indices.index(base) + 1
                base = indices[base_index]
                rnos.append(prev_base)
                rnos.append(base)
            return rnos
        elif 10 < n <50:
            base,factor = 10,10
            rnos.append(base)
            result = n - base
            while result > 0:
                rnos.append(factor)
                result = result - factor
            if rnos.count(factor) > 3:
                for n in rnos[:]:
                    rnos.remove(n)
                indices = list(roman_dict.keys())
                indices.sort()
                prev_base = base
                base_index = indices.index(base) + 1
                base = indices[base_index]
                rnos.append(prev_base)
                rnos.append(base)
            return rnos
        elif 50 < n < 100:
            base, factor = 50,10
            rnos.append(base)
            result = n - base
            while result > 0:
                rnos.append(factor)
                result = result - factor
            if rnos.count(factor) > 3:
                for n in rnos[:]:
                    rnos.remove(n)
                indices = list(roman_dict.keys())
                indices.sort()
                prev_base_index = indices.index(base) - 1
                prev_base = indices[prev_base_index]
                base_index = indices.index(base) + 1
                base = indices[base_index]
                rnos.append(prev_base)
                rnos.append(base)
            return rnos
        elif 100 < n < 500:
            base, factor = 100, 100
            rnos.append(base)
            result = n - base
            while result > 0:
                rnos.append(factor)
                result = result - factor
            if rnos.count(factor) > 3:
                for n in rnos[:]:
                    rnos.remove(n)
                indices = list(roman_dict.keys())
                indices.sort()
                prev_base = base
                base_index = indices.index(base) + 1
                base = indices[base_index]
                rnos.append(prev_base)
                rnos.append(base)
            return rnos
        elif 500 < n < 1000:
            base, factor = 500, 100
            rnos.append(base)
            result = n - base
            while result > 0:
                rnos.append(factor)
                result = result - factor
            if rnos.count(factor) > 3:
                for n in rnos[:]:
                    rnos.remove(n)
                indices = list(roman_dict.keys())
                indices.sort()
                prev_base_index = indices.index(base) - 1
                prev_base = indices[prev_base_index]
                base_index = indices.index(base) + 1
                base = indices[base_index]
                rnos.append(prev_base)
                rnos.append(base)
            return rnos


def main():
    number = int(input("Enter the Integer: "))
    if number > 1000:
        print('Sorry, I know uptil 1000 only.')
        exit()
    if number in roman_dict:
        print("Roman: ",roman_dict[number])
    else:
        romans = []
        res = sep_num(number)
        for each in res:
            rvalues = get_roman(each)
            for value in rvalues:
                romans.append(roman_dict[value])
        print("Roman: ",''.join(romans))

if __name__ == '__main__':
    main()
