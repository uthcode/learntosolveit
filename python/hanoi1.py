def h(n,f,t,s):
    h(n-1,f,s,t)
    print f,t
    h(n-1,s,t,f)
h(3,'a','c','b')
