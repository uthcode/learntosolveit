# A bit of Lambda Calculus illustrated in Python.
#
# This does not use Python's built-in 'eval' or 'exec' functions!


# Currying
#
# From a function with 2 args, f(x, y), and a value for the 1st arg,
# we can create a new function with one argument fx(y) = f(x, y).
# This is called "Currying" (after the idea's inventor, a Mr. Curry).
#
# To implement this we create a class member, of which fx is a method;
# f and x are stored as data attributes of the member.

class _CurryClass():
       def new(self, (f, x)):
               self.f = f
               self.x = x
               return self
       def fx(self, y):
               return self.f(self.x, y)

def CURRY(f, x):
       # NB: f is not "simple": it has 2 arguments
       return _CurryClass().new(f, x).fx


# Numbers in Lambda Calculus
#
# In the lambda calculus, natural numbers are represented by
# higher-order functions Ntimes(f, x) that yield f applied N
# times to x, e.g., Twice(f, x) = f(f(x)).
# As far as I understand, there is no difference in real lambda
# calculus between
#      lambda f x : f(f(x))
# and
#      lambda f : f o f        # 'o' means function composition
# but in Python we have to write the first as Twice(f, x) and
# the second as twice(f).

def Never(f, x): return x
def Once(f, x): return f(x)
def Twice(f, x): return f(f(x))
def Thrice(f, x): return f(f(f(x)))
def Fourfold(f, x): return f(f(f(f(x))))
# (etc.)

def never(f): return CURRY(Never, f)
def once(f): return CURRY(Once, f)
def twice(f): return CURRY(Twice, f)
def thrice(f): return CURRY(Thrice, f)
def fourfold(f): return CURRY(Fourfold, f)
# (etc.)


# NB: actually 'ntimes' is less concrete than 'Ntimes', as
# 'ntimes' returns a function, while 'Ntimes' returns a value
# similar to what f(x) returns.  'Ntimes' can be derived
# from 'ntimes', as follows:
#      def Ntimes(f, x): return ntimes(f)(x)
# but this doesn't help us since 'ntimes' can only be defined
# using Ntimes (or a trick like the one used by CURRY).


# Arithmetic in Lambda Calculus
#
# We can perform simple arithmetic on the un-curried versions, e.g.,
#      Successor(Twice)        = Thrice        (2+1)
#      Sum(Thrice, Twice)      = Fivefold      (3+2)
#      Product(Thrice, Twice)  = Sixfold       (3*2)
#      Power(Thrice, Twice)    = Ninefold      (3**2)
#
# First we define versions that need f and x arguments.
# They have funny argument forms so the final functions can
# use CURRY, which only works on functions of exactly 2 arguments.

def SUCCESSOR(Ntimes, (f, x)): return f(Ntimes(f, x))
def SUCCESSOR(Ntimes, (f, x)): return Ntimes(f, f(x))  # Same effect
def SUM(Ntimes, (Mtimes, (f, x))): return Ntimes(f, Mtimes(f, x))
def PRODUCT(Ntimes, (Mtimes, (f, x))): return Ntimes(CURRY(Mtimes, f), x)
def POWER(Ntimes, (Mtimes, (f, x))):
       return Mtimes(CURRY(CURRY, Ntimes), f)(x)

def Successor(Ntimes): return CURRY(SUCCESSOR, Ntimes)
def Sum(Ntimes, Mtimes): return CURRY(CURRY(SUM, Ntimes), Mtimes)
def Product(Ntimes, Mtimes): return CURRY(CURRY(PRODUCT, Ntimes), Mtimes)
def Power(Ntimes, Mtimes): return CURRY(CURRY(POWER, Ntimes), Mtimes)


# Sorry, I don't have a clue on how to do subtraction or division...


# References
#
# All I know about lambda calculus is from Roger Penrose's
# The Emperor's New Mind, Chapter 2.


# P.S.: Here is a Lambda function in Python.
# It uses 'exec' and expects two strings to describe the arguments
# and the function expression.  Example:
#      lambda('x', 'x+1')
# defines the successor function.

def lambda(args, expr):
       if '\n' in args or '\n' in expr:
               raise RuntimeError, 'lambda: no cheating!'
       stmt = 'def func(' + args + '): return ' + expr + '\n'
       print 'lambda:', stmt,
       exec(stmt)
       return func


# P.P.S.S.: Here is a way to construct Ntimes and ntimes directly.
# Example:
#      GenericNtimes(4)
# is equivalent to Fourfold.

class _GenericNtimesClass():
       def new(self, n):
               self.n = n
               return self
       def Ntimes(self, (f, x)):
               n = self.n
               while n > 0: x, n = f(x), n-1
               return x

def GenericNtimes(n):
       return _GenericNtimesClass().new(n).Ntimes


# To construct any 'ntimes' function from the corresponding 'Ntimes',
# we use a trick as used by CURRY.  For example,
#      Ntimes2ntimes(Fourfold)
# yields a function equivalent to fourfold.

class _Ntimes2ntimesClass():
       def new(self, Ntimes):
               self.Ntimes = Ntimes
               return self
       def ntimes(self, f):
               return CURRY(self.Ntimes, f)

def Ntimes2ntimes(Ntimes): return _Ntimes2ntimesClass().new(Ntimes).ntimes


# This allows us to construct generic 'ntimes' functions.  Example:
#      generic_ntimes(3)
# is the same as thrice.

def generic_ntimes(n): return Ntimes2ntimes(GenericNtimes(n))
