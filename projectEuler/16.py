def solve():
	ans = 1
	for i in range(1000):
		ans = ans * 2
	res = str(ans)
	answer = 0
	for i in range(len(res)):
		answer = answer + int(res[i])
	print(answer)
solve()
