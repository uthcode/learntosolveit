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

class RecoverSequence(Recover):
    def __init__(self, n, debugseq):
        self.n = n
        self.debugseq = list(debugseq)
        self.debug = 0

    def cmp(self, a, b):
        if self.debugseq.pop(0) == "1":
            return True
        else:
            return False

    def solve(self):
        seq = range(1,N+1)
        orig = self.merge_sort(seq)
        return self.checksum([orig.index(x+1)+1 for x in range(self.n)])

#obj = Recover([3,5,2,4,1], 0)
#print obj.solve()

if __name__ == '__main__':
    T = int(raw_input())
    for each in range(T):
        N = int(raw_input())
        seq = raw_input()
        obj = RecoverSequence(N, seq)
        print 'Case #%d: %d' % (T+1, obj.solve())
