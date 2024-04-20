from PIL import Image, ImageDraw
from easyinput import read

# Dibuixa un rectangle:
#    nw = cantonada superior esquerra
#    se = cantonada inferior dreta
def DibuixaRectangle(nw, se, color):
	dib.polygon([nw, (nw[0], se[1]), se, (se[0], nw[1])], color)

n = read(int)
color_f = [read(str) for _ in range(n)]
m = read(int)
color_s = [read(str) for _ in range(m)]

img = Image.new('RGB', (100*m, 150*n), 'Grey')
dib = ImageDraw.Draw(img)

for i in range(n):
	for j in range(m):
		x = 100*j
		y = 150*i
		dib.ellipse([(x + 35, y + 5), (x + 64, y + 34)], "AntiqueWhite")
		DibuixaRectangle((x + 5, y + 40), (x + 94, y + 54), color_s[j])
		DibuixaRectangle((x + 30, y + 55), (x + 69, y + 94), color_s[j])
		dib.polygon([(x + 30, y + 100), (x + 69, y + 100), (x + 79, y + 144), (x + 20, y + 144)], color_f[i])

img.save('output.png')
