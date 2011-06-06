def positive(x):
	return x > 0

def negative(x):
	return x < 0

def foo(a: positive, b: negative)->positive:
	return a-b
