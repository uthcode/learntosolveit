from threading import Thread
from operator import add
import random

class Bank(object):
    def __init__(self, naccounts, ibalance):
        self._naccounts = naccounts
        self._ibalance = ibalance

        self.accounts = []
        for n in range(self._naccounts):
            self.accounts.append(self._ibalance)

    def size(self):
        return len(self.accounts)

    def getTotalBalance(self):
        return reduce(add, self.accounts)

    def transfer(self, name, afrom, ato, amount):

        if self.accounts[afrom] < amount: return

        self.accounts[afrom] -= amount
        self.accounts[ato] += amount

        print "%-9s %8.2f from %2d to %2d Balance: %10.2f" % \
                (name, amount, afrom, ato, self.getTotalBalance())


class transfer(Thread):
    def __init__(self, bank, afrom, maxamt):
        Thread.__init__(self)
        self._bank = bank
        self._afrom = afrom
        self._maxamt = maxamt

    def run(self):
        while True:
        #for i in range(0, 3000):
            ato = random.choice(range(b.size()))
            amount = round((self._maxamt * random.random()), 2)
            self._bank.transfer(self.getName(), self._afrom, ato, amount)

naccounts = 2
initial_balance = 10

b = Bank(naccounts, initial_balance)

threads = []

for i in range(0, naccounts):
    threads.append(transfer(b, i, 10))
    threads[i].start()

for i in range(0, naccounts):
    threads[i].join()
