def mygen():
  """Yield 5 until something else is passed back via send()"""
  a = 5
  while True:
    f = yield(a) #yield a and possibly get f in return
    if f is not None: a = f  #store the new value

g = mygen()
print g.next()
print g.next()
g.send(7)
print g.next()
