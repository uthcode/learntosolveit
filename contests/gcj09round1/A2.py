import sys

memo = [dict() for _ in range(0,11)]

def isHappy(n, b):
	if n == 1:
		return True
	if n in memo[b]:
		return memo[b][n]

	s = 0
	i = n
	while i > 0:
		s += (i%b)*(i%b)
		i //= b
	memo[b][n] = False
	v = isHappy(s, b)
	memo[b][n] = v
	return v

def happyGen(B, i):
	if i == len(B):
		n = 2
		while True:
			yield n
			n = n+1
	else:
		for n in happyGen(B,i+1):
			if isHappy(n, B[i]):
				yield n

CN = int(sys.stdin.next())
for C in range(1, CN+1):
	print "Case #%d:"%(C),
	B = map(int, sys.stdin.next().split(" "))
	for n in happyGen(B, 0):
		print n
		break
