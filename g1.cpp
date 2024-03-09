from PIL import Image, ImageDraw
from easyinput import read

MARGE = 5
MARGE_ENTRE_BARRES = 10
ALCADA_BARRA = 100
AMPLADA_BARRA = 5


# Dibuixa un rectangle donat el punt superior esquerre (x,y), la seva amplada l i la seva altura h
def DibuixaRectangle(x, y, l, h, color):
    dib.polygon([(x, y), (x + l-1, y), (x + l-1, y + h-1), (x, y + h-1)], color)


a = [int(x) for x in input()]
n = len(a)
amplada_imatge = sum(a) * AMPLADA_BARRA + (n-1) * MARGE_ENTRE_BARRES + 2 * MARGE
alcada_imatge = ALCADA_BARRA + 2 * MARGE

img = Image.new('RGB', (amplada_imatge, alcada_imatge), 'Red')
dib = ImageDraw.Draw(img)

x_actual = MARGE
for d in a:
    DibuixaRectangle(x_actual, MARGE, AMPLADA_BARRA * d, ALCADA_BARRA, 'Black')
    x_actual += AMPLADA_BARRA * d + MARGE_ENTRE_BARRES

img.save("output.png")