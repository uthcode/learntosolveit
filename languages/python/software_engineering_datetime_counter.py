import datetime

def withtimestamp():
	format = "%Y-%m-%d-%H-%M-%S"
	return datetime.datetime.now().strftime(format=format)

if __name__ == "__main__":
	print(withtimestamp())


