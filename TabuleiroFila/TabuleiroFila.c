#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TabuleiroFila.h"

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int filaVazia(Fila *f) {
    return f->inicio == NULL;
}

void enfileirar(Fila *f, Ponto p) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->p = p;
    novoNo->proximo = NULL;
    if (filaVazia(f)) {
        f->inicio = novoNo;
        f->fim = novoNo;
    } else {
        f->fim->proximo = novoNo;
        f->fim = novoNo;
    }
}

Ponto desenfileirar(Fila *f) {
    Ponto p;
    if (!filaVazia(f)) {
        No *temp = f->inicio;
        p = temp->p;
        f->inicio = f->inicio->proximo;
        if (f->inicio == NULL) {
            f->fim = NULL;
        }
        free(temp);
    }
    return p;
}

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if ((i == 0 && j == 0) || (i == 9 && j == 9) || (i == 1 && j == 1)) {
                tabuleiro[i][j] = 0;
            } else {
                tabuleiro[i][j] = (rand() % 4 == 0) ? -1 : 0;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ehValido(int x, int y) {
    return x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO;
}

void encontrarCaminho(int tabuleiro[TAMANHO][TAMANHO]) {
    Fila fila;
    inicializarFila(&fila);

    int visitado[TAMANHO][TAMANHO] = {0};
    Ponto pai[TAMANHO][TAMANHO];

    Ponto inicio = {1, 1};
    Ponto fim = {9, 9};

    enfileirar(&fila, inicio);
    visitado[inicio.x][inicio.y] = 1;

    int encontrado = 0;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!filaVazia(&fila)) {
        Ponto atual = desenfileirar(&fila);

        if (atual.x == fim.x && atual.y == fim.y) {
            encontrado = 1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int novoX = atual.x + dx[i];
            int novoY = atual.y + dy[i];

            if (ehValido(novoX, novoY) && tabuleiro[novoX][novoY] == 0 && !visitado[novoX][novoY]) {
                visitado[novoX][novoY] = 1;
                Ponto proximo = {novoX, novoY};
                pai[novoX][novoY] = atual;
                enfileirar(&fila, proximo);
            }
        }
    }

    if (encontrado) {
        printf("Caminho escolhido:\n");
        Ponto caminho[TAMANHO * TAMANHO];
        int index = 0;
        Ponto atual = fim;
        while (atual.x != inicio.x || atual.y != inicio.y) {
            caminho[index++] = atual;
            atual = pai[atual.x][atual.y];
        }
        caminho[index++] = inicio;

        for (int i = index - 1; i >= 0; i--) {
            printf("(%d, %d)\n", caminho[i].x, caminho[i].y);
        }
    } else {
        printf("Nenhum caminho encontrado.\n");
    }
}