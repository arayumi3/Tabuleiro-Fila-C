#include "TabuleiroFila.h"

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro);
    encontrarCaminho(tabuleiro);
    return 0;
}