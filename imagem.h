#ifndef _PIXEL_PONTO_H_
#define _PIXEL_PONTO_H_

#include <fstream>
#include <iostream>

using namespace std;

class Imagem {
   private:
    unsigned NL, NC;
    char **x;
    void criar(const unsigned &NumLi, const unsigned &NumCo) {
        NL = NumLi;
        NC = NumCo;
        x = new char *[NL];
        for (unsigned i = 0; i < NL; i++) x[i] = new char[NC];
    }

    void copiar(const Imagem &I) {
        if (NC == 0 && NL == 0 && x == NULL) {
            NL = I.NL;
            NC = I.NC;
            x = new char *[NL];
            for (unsigned i = 0; i < NL; i++) x[i] = new char[NC];
            for (unsigned i = 0; i < NL; i++) {
                for (unsigned j = 0; j < NC; j++) x[i][j] = I.x[i][j];
            }
        } else
            cerr << "Erro inesperado";
    }
    void limpar() {
        if (x != NULL) {
            for (unsigned i = 0; i < NL; i++) delete[] x[i];
            delete[] x;
        }
        x = NULL;
        NC = NL = 0;
    }

   public:
    inline Imagem() : NL(0), NC(0), x(NULL){};
    inline Imagem(const Imagem &I) : NL(0), NC(0), x(NULL) { copiar(I); }
    inline explicit Imagem(const unsigned &NumLi, const unsigned &NumCo) {
        criar(NumLi, NumCo);
    }
    ~Imagem() { limpar(); }
    void operator=(const Imagem &I) {
        if (this != &I) {
            limpar();
            copiar(I);
        }
    }

    inline uint8_t getPixel(const unsigned &i, const unsigned &j) const {
        return x[i][j];
    }
    inline void setPixel(const unsigned &i, const unsigned &j, char &pixel) {
        if (j >= 0 && j <= NC && i >= 0 && i <= NL) {
            x[i][j] = pixel;
        }
    }
    inline unsigned getNL() const { return NL; }
    inline unsigned getNC() const { return NC; }

    // friend ostream &operator<<(ostream &X, const Imagem &I);
    // friend istream &operator>>(istream &X, Imagem &I);

    void paintRectangle(unsigned &x1, unsigned &y1, unsigned &x2, unsigned &y2,
                        char &cor) {
        if (x1 >= 0 && x2 <= NC && y1 >= 0 && y2 <= NL) {
            for (unsigned i = x1; i <= x2; i++) {
                for (unsigned j = y1; j <= y2; j++) x[i][j] = cor;
            }
        }
    }
    void salvaImagem(const char *nome) const {
        ofstream f(nome);

        f << "P2\n";
        f << NC << ' ' << NL << endl;
        f << (unsigned)255 << endl;
        for (unsigned i = 0; i < NL; i++) {
            for (unsigned j = 0; j < NC; j++) {
                f << (unsigned)x[i][j] << ' ';
            }
            f << endl;
        }
        f.close();
        cout << "Arquivo " << nome << " salvo!\n";
    }
};

#endif  // _PIXEL_PONTO_H_
