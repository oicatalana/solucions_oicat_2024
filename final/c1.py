from easyinput import read

def Convert(a):
	if a[2] == "milles":
		a[1] *= 1609
	else:
		a[1] *= 1000


a = read(str, int, str)
b = read(str, int, str)
Convert(a)
Convert(b)
if a[1] > b[1]:
	print(a[0])
else:
	print(b[0])