def solve():
	ans = 1
	for i in range(100):
		ans = ans * (i+1)
	rest = str(ans)
	res = 0
	for i in range(len(rest)):
		res = res + int(rest[i])
	print(res)
solve()
