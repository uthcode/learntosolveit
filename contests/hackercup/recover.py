class Recover(object):
    def __init__(self, seq, debug):
        self.sequence = seq
        self.debug = debug

    def cmp(self, a, b):
        return a < b

    def merge_sort(self, sequence):
        n = len(sequence)
        if n <= 1:
            return sequence
        mid = n/2
        first_half = self.merge_sort(sequence[0:mid])
        second_half = self.merge_sort(sequence[mid:n])
        return self.merge(first_half, second_half)

    def merge(self, a, b):
        result = []
        while a and b:
            if self.cmp(a[0], b[0]):
                if self.debug: print 1
                result.append(a.pop(0))
            else:
                if self.debug: print 2
                result.append(b.pop(0))
        result.extend(a)
        result.extend(b)
        return result

    def checksum(self, seq):
        result = 1
        for s in seq:
            result = (31 * result + s) % 1000003
        return result

    def solve(self):
        return self.checksum(self.merge_sort(self.sequence))

obj = Recover([3,5,2,4,1], 1)
print obj.solve()
