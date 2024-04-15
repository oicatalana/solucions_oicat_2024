from easyinput import read

n = read(int)
for _ in range(n):
	a = [read(int) for _ in range(4)]
	a.sort()
	if a[0] + a[1] + a[2] > a[3]:
		print("si")
	else:
		print("no")