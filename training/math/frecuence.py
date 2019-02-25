import sys

def blank(x):
	if(x<10):
		return 4
	elif(x<100):
		return 3
	else:
		return 2

def solve(x):
	res = str(f[x])
	cnt = []
	for i in range(10):
		cnt.append(0)
	for i in res:
		cnt[int(i)] +=1
	print(x,end="")
	print("! --")
	for i in range(5):
		for j in range(3):
			print(" ",end="")
		print("(",end="")
		print(i,end="")
		print(")",end="")
		many = blank(cnt[i])
		for j in range(many):
			print(" ",end="")
		if(i==4):
			print(cnt[i])
		else:
			print(cnt[i],end=" ")
	for i in range(5,10):
		for j in range(3):
			print(" ",end="")
		print("(",end="")
		print(i,end="")
		print(")",end="")
		many = blank(cnt[i])
		for j in range(many):
			print(" ",end="")
		if(i==9):
			print(cnt[i])
		else:
			print(cnt[i],end=" ")

f = []
f.append(1)
for i in range(1,367):
	f.append(f[i-1]*i)

for line in sys.stdin:
	if(line=="0\n"):
		break
	solve(int(line))
