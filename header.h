#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>

typedef struct No {
    int id;
    int quantidade;
    float valor;
    float unidade;
    char produto[50];
    struct No* ant;
    struct No* prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} ListaCDE;

int insereItem(ListaCDE *l, int item, int quantidade, char nome[], float valor, float unidade);
int removeItem(ListaCDE *l, int item, char nome[], float preco, float unidade);
void displayLista(ListaCDE *l);
void cria(ListaCDE *l);
void tempoPreparo();

#endif  // HEADER_H
