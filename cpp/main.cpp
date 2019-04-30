#include <fstream>
#include <iostream>
#include "imagem.h"
using namespace std;

int main() {
    char cor(127);
    char branco(255);
    char preto(0);
    Imagem I(240, 320);
    unsigned x1(30), y1(10), x2(180), y2(160), x11(50), y11(50), x22(200),
        y22(200);

    for (unsigned i = 0; i < I.getNL(); i++) {
        for (unsigned j = 0; j < I.getNC(); j++) I.setPixel(i, j, cor);
    }

    I.paintRectangle(x1, y1, x2, y2, preto);
    I.paintRectangle(x11, y11, x22, y22, branco);

    I.salvaImagem("imagemTeste.pgm");

    return 0;
}
