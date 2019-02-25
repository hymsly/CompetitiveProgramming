
caso = 1

def solve():
	word = input()
	ans = f[len(word)]
	for i in range(26):
		cnt[i] = 0
	for x in word:
		if x=='A':
			cnt[0] += 1
		elif x=='B':
			cnt[1] += 1
		elif x=='C':
			cnt[2] += 1
		elif x=='D':
			cnt[3] += 1
		elif x=='E':
			cnt[4] += 1
		elif x=='F':
			cnt[5] += 1
		elif x=='G':
			cnt[6] += 1
		elif x=='H':
			cnt[7] += 1
		elif x=='I':
			cnt[8] += 1
		elif x=='J':
			cnt[9] += 1
		elif x=='K':
			cnt[10] += 1
		elif x=='L':
			cnt[11] += 1
		elif x=='M':
			cnt[12] += 1
		elif x=='N':
			cnt[13] += 1
		elif x=='O':
			cnt[14] += 1
		elif x=='P':
			cnt[15] += 1
		elif x=='Q':
			cnt[16] += 1
		elif x=='R':
			cnt[17] += 1
		elif x=='S':
			cnt[18] += 1
		elif x=='T':
			cnt[19] += 1
		elif x=='U':
			cnt[20] += 1
		elif x=='V':
			cnt[21] += 1
		elif x=='W':
			cnt[22] += 1
		elif x=='X':
			cnt[23] += 1
		elif x=='Y':
			cnt[24] += 1
		elif x=='Z':
			cnt[25] += 1
	for i in range(26):
		ans = ans // f[cnt[i]]
	print("Data set ",end="")
	print(caso,end="")
	print(":",ans)

f = []
f.append(1);
for i in range(1,30001):
	f.append(f[i-1]*i)
		
cnt = []
for i in range(26):
	cnt.append(0)

t = int(input())
for i in range(t):
	solve()
	caso += 1
