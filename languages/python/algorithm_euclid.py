
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return (b*a)/gcd(a, b)

a = 80
b = 72
print(gcd(a, b))
print(lcm(a, b))
