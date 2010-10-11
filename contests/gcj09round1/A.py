import sys

memo = dict()

def isHappy(n, b):  # Get the number and the base.
	if n == 1: # If the number is 1.
		return True  # This is a happy number,
	if (n,b) in memo: # Create a global dict. Store num and base. 
		return memo[(n,b)] # if number number and base stored and return value

	s = 0 # sum = 0
	i = n # i = number
	while i > 0: # while i is greater than 0
		s += (i%b)*(i%b) # s += (i%b) * (i%b)
		i //= b          # i //= b
	memo[(n,b)] = False # I find it confusing at this point
	v = isHappy(s, b)  # Will it return True for just 1
	memo[(n,b)] = v   # This one is required. as I tested it.
	return v  # This returns to recursion too.


CN = int(sys.stdin.next()) # reads the number of test cases.
for C in range(1, CN+1): # test case 1 to CN
	print "Case #%d:"%(C), # print Test Case Number.

	B = map(int, sys.stdin.next().split(" ")) # Get the bases in B.

	n = 2  # Start with 2.
	while True: # Infinite Loop. ( I actually feared this and was looking for something else)
		happy_all = True # Set a variable by name happy_all to True.
		for b in B: # take each base.
			if not isHappy(n,b): # See if the Number is a happy number in base b.
				happy_all = False
		if happy_all:
			print n
			break
		n += 1
