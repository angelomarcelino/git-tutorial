from imagem import Imagem as img

cor = 127
branco = 255
preto = 0
img = img(240, 320, 127)

img.paintRectangle(30, 10, 180, 160, preto)
img.paintRectangle(50, 50, 200, 200, branco)

img.salvaImagem("imagemTestePython.pgm")
