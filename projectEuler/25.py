def solve():
	a = 1
	b = 1
	for i in range (3,10000):
		c = a+b
		a = b
		b = c
		if(len(str(c))==1000):
			return i

print(solve())
