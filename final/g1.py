from PIL import Image, ImageDraw
from easyinput import read

# Dibuixa un rectangle:
#    nw = cantonada superior esquerra
#    se = cantonada inferior dreta
def DibuixaRectangle(nw, se, color):
	dib.polygon([nw, (nw[0], se[1]), se, (se[0], nw[1])], color)

n = read(int)
a = [read(int) for _ in range(n)]

alcada = 10 + 40 + max(a) + 20
llargada = 20 + 20*n + 10*(n-1) + 20
img = Image.new('RGB', (llargada, alcada), 'MidnightBlue')
dib = ImageDraw.Draw(img)

DibuixaRectangle((0,0), (llargada-1, 10 - 1), "Sienna")
x = 20
for i in range(n):
	DibuixaRectangle((x + 9, 10), (x + 10, 49), "White")
	dib.ellipse([(x, 50), (x + 19, 69)], "Grey")
	DibuixaRectangle((x, 60), (x + 19, a[i] + 39), "Grey")
	dib.ellipse([(x, a[i] + 30), (x + 19, a[i] + 49)], "Firebrick")
	x += 30

img.save('output.png')
