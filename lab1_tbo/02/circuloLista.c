#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

typedef struct _node node;

struct _node
{
    char marcado;
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

    c->circulo = calloc(1, sizeof(node));
    node* prim = c->circulo;
    for(int i = 0; i < n;)

    return c;
}

int achaLider(circulo* c) {
    
}

void liberaCirculo(circulo* c) {
}