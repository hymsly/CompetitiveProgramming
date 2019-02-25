import sys

memo = []

def dp(x):
	if(memo[x] != -1):
		return memo[x]
	if x==0:
		return 1
	if x==1:
		return 1
	memo[x] = dp(x-1)+2*dp(x-2)
	return memo[x]

for i in range(300):
	memo.append(-1)

for line in sys.stdin:
	n = int(line)
	print(dp(n))
