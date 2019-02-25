def div(a,b):
	if (a%b==0):
		return True
	else:
		return False

def cnt(x):
	y = int(x)
	while y%2==0:
		y= y/2
	while y%5==0:
		y = y/5
	a = 9
	ans = 1
	while True:
		if div(a,y):
			break
		a = 10*a
		a = a + 9
		ans = ans +1
	return ans
entrada = input()
arr = entrada.split(' ')
for i in range(len(arr)):
	valor = cnt(arr[i])
	print(arr[i],end=" ")
	print(valor)

