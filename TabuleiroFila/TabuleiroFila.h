#ifndef TABULEIROFILA_H
#define TABULEIROFILA_H

#define TAMANHO 10

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct No {
    Ponto p;
    struct No* proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializarFila(Fila *f);
int filaVazia(Fila *f);
void enfileirar(Fila *f, Ponto p);
Ponto desenfileirar(Fila *f);

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
void encontrarCaminho(int tabuleiro[TAMANHO][TAMANHO]);

#endif