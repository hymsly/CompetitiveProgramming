import sys


mod = int(1092)
f = []
f.append(0)
f.append(1)
for i in range(2,50001):
	f.append((2*f[i-1]+f[i-2])%mod)
modul = [2,3,4,7,13]
base = "Pell" + chr(39) + "s number"
for line in sys.stdin:
	x = int(line)
	val = f[x]
	div = False
	for i in range(len(modul)):
		if(val%modul[i]==0):
			print(base,x,"is divisible by",modul[i])
			div = True
	if(not div):
		print("-1")

