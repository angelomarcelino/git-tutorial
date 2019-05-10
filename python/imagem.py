# Classe Imagem

class Imagem:

    def __init__(self, NL, NC, color):
        try:
            self.NL = NL
            self.NC = NC
            self.x = [[color for x in range(NC)] for y in range(NL)]

        except:
            self.NL = 0
            self.NC = 0
            self.x = [[0 for x in range(NC)] for y in range(NL)]

    def getPixel(self, i, j):
        return self.x[i][j]

    def setPixel(self, i, j, pixel):
        if j >= 0 and j <= self.NC and i >= 0 and i <= self.NL:
            self.x[i][j] = pixel
        pass

    def getNL(self):
        return self.NL

    def getNC(self):
        return self.NC

    def paintRectangle(self, x1, y1, x2, y2, cor):
        if x1 >= 0 and x2 <= self.NC and y1 >= 0 and y2 <= self.NL:
            for i in range(x1, x2):
                for j in range(y1, y2):
                    self.x[i][j] = cor

    def salvaImagem(self, nome):
        file = open(nome, "w+")
        file.write("P2\n")
        coisa = str(self.NC) + " " + str(self.NL) + "\n"
        file.write(coisa)

        for i in range(0, self.NL):
            for j in range(0, self.NC):
                file.write(str(self.x[i][j]) + " ")
            file.write("\n")

        file.close()
        print("Arquivo " + str(nome) + " salvo!")
        pass

