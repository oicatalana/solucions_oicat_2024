from easyinput import read
from PIL import Image, ImageDraw

# Dibuixa un rectangle:
#    nw = cantonada superior esquerra
#    se = cantonada inferior dreta
def DrawRectangle(nw, se, color):
    dib.polygon([nw, (nw[0], se[1]), se, (se[0], nw[1])], color)


m, n = read(int,int)
a = [read(str) for _ in range(n)]

img = Image.new('RGB', (30*m, 30*n), 'Green')
dib = ImageDraw.Draw(img)

vist = [[False for _ in range(m)] for _ in range(n)]
pos = [m//2, n-1]
direccio = 0
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
while pos[0] >= 0 and pos[0] < m and pos[1] >= 0 and pos[1] < n:
    vist[pos[1]][pos[0]] = True
    if a[pos[1]][pos[0]] == 'X':
        direccio = (direccio + 1) % 4
    pos[0] += dx[direccio]
    pos[1] += dy[direccio]

for i in range(n):
    for j in range(m):
        col = 'Blue'
        if vist[i][j]:
            DrawRectangle((30*j, 30*i), (30*j + 29, 30*i + 29), 'Yellow')
            col = 'Red'
        if a[i][j] == 'X':
            dib.ellipse([(30*j, 30*i), (30*j + 29, 30*i + 29)], col)

img.save('output.png')