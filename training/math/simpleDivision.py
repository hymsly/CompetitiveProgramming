import sys

def gcd(a,b):
	if(b==0):
		return a
	return gcd(b,(a%b + b)%b)
	
def solve(data):
	data.sort()
	#print(data)
	ans = 0
	for i in range(1,len(data)):
		#print(data[i])
		ans = gcd(ans,int(data[i])-int(data[i-1]))
	print(abs(ans))

for line in sys.stdin:
	if(line=="0\n"):
		break
	data = line.split()[:-1]
	#print(data)
	solve(data)
