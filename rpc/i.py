import sys
sys.setrecursionlimit(10000)
f = []
def expmod(b,e,m):
	if(e==0):
		return 1
	q = expmod(b,e//2,m)
	q = (q*q)%m
	if(e%2==1):
		return (b*q)%m
	else:
		return q

def is_prime_prob(n,a):
	if(n==a):
		return True
	s=0
	d=n-1
	while(d%2==0):
		s=s+1
		d=d//2
	x=expmod(a,d,n)
	if(x==1 or x+1==n):
		return True
	for i in range(s-1):
		x=(x*x)%n
		if(x==1):
			return False
		if(x+1==n):
			return True
	return False

def rabin(n):
	if (n==1):
		return False
	ar = [2,3,5,7,11,13,17,19,23]
	for i in range(len(ar)):
		if(not is_prime_prob(n,ar[i])):
			return False
	return True

def solve(a,b):
	num = f[a+b]-1
	print("2^",end="")
	print(a+b,end="")
	if(rabin(num)):
		print("-1 is prime")
	else:
		print("-1 not prime")

f.append(1)
for i in range(1,2001):
	f.append(f[i-1]*2)
for line in sys.stdin:
	data = line.split()
	a = int(data[0])
	b = int(data[1])
	solve(a,b)
