entrada = input()
names = entrada.split(',')
names.sort()
for i in range(len(names)):
	print(names[i][1:-1])
