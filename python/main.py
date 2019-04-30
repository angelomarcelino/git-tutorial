from imagem import Imagem as img

cor = 127
branco = 255
preto = 0
img = img(240, 320, 127)
x1 = 30
y1 = 10
x2 = 180
y2 = 160
x11 = 50
y11 = 50
x22 = 200
y22 = 200

img.paintRectangle(x1, y1, x2, y2, preto)
img.paintRectangle(x11, y11, x22, y22, branco)

img.salvaImagem("imagemTestePython.pgm")
