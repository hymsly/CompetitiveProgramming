n = int(input())
x = list(map(int,input().split()))
y = list(map(int,input().split()))
z = list(map(int,input().split()))
ans1 = 0
ans2 = 0
for i in range(0,n):
	ans1 += (y[i]-x[i])**2
	ans2 += (z[i]-x[i])**2
if(ans1<=ans2):
	print("Yan")
else:
	print("MaratonIME")