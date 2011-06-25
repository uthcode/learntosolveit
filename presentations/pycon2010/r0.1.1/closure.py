def make_adder(addend):
    def adder(augent):
        return augent + addend
    return adder

p = make_adder(64)
print p(36)

q = make_adder(36)
print q(64)
