import sys

f = []
f.append(1)
for i in range(1,1000000):
	f.append(f[i-1]*i)
def solve(a,b):
	ans = f[a]
	ans = ans // f[b]
	ans = ans // f[a-b]
	#print(ans)
	print(len(str(ans)))

for line in sys.stdin:
	data = line.split()
	solve(int(data[0]),int(data[1]))
