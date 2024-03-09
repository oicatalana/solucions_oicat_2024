from PIL import Image, ImageDraw
from easyinput import read, read_many

# Dibuixa un cercle amb el diametre i color donats, tal que la cantonada 
# esquerra superior del quadrat que el conté es troba al píxel (x,y)
def DibuixaCercle(x, y, diametre, color):
    dib.ellipse([(x, y), (x + diametre - 1, y + diametre - 1)], color)



# Mesures de la imatge
MARGE = 5
MARGE_ENTRE_BOLES = 10
DIAMETRE = 75
amplada = 3 * DIAMETRE + 2 * MARGE + 2 * MARGE_ENTRE_BOLES
alcada = DIAMETRE + 2 * MARGE

img = Image.new('RGB', (amplada, alcada), "AntiqueWhite")
dib = ImageDraw.Draw(img)

# Llegim la posició inicial 
v = [read(str) for _ in range(3)]

# Per cada instrucció, permutem els colors de les boles corresponents.
for instruccio in read_many(str):
    a, b = int(instruccio[0])-1, int(instruccio[-1])-1
    v[a], v[b] = v[b], v[a]

# Dibuixem
x_esquerra = MARGE
for color in v:
    DibuixaCercle(x_esquerra, MARGE, DIAMETRE, color)
    x_esquerra += DIAMETRE + MARGE_ENTRE_BOLES

img.save('output.png')