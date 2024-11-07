#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

typedef struct _node node;

struct _node
{
    int id;
    node* prox;
};


struct _circulo {
    node* circulo;
    int n, m;
};

circulo* criaCirculo(int n, int m) {
    circulo* c = malloc(sizeof(circulo));

    c->m = m;
    c->n = n;

    c->circulo = malloc(sizeof(node));

    node* atual = c->circulo;
    atual->id = 1;
    for(int i = 2; i <= n; i++) {
        node* prox = malloc(sizeof(node));
        prox->id = i;
        atual->prox = prox;
        atual = prox;
    }
    atual->prox = c->circulo;

    return c;
}

int achaLider(circulo* c) {
    int restantes = c->n;
    int n = c->n;
    int m = c->m;

    node* atual = c->circulo;
    while(restantes > 1) {
        for(int i = 1; i < (m - 1); i++) atual = atual->prox;

        node* morto = atual->prox;
        atual->prox = morto->prox;
        free(morto);
        atual = atual->prox;

        restantes--;
    }
    c->circulo = atual;
    return atual->id;
}

void liberaCirculo(circulo* c) {
    if(!c) return;
    if(!c->circulo) return;
    free(c->circulo);
    free(c);
}