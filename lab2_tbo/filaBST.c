#include <stdio.h>
#include <stdlib.h>
#include "filaBST.h"

typedef struct _node node;

struct _node {
    node* ant;
    node* prox;
    bst* noBST;
};


struct _filaBST {
    node* prim;
    node* ult;
};

int vazia(filaBST* f) {
    return (!f->prim);
}

filaBST* criaFilaBST() {
    return (filaBST*)calloc(1, sizeof(filaBST));
}

void enqueue(filaBST* f, bst* noBST) {
    node* novo = malloc(sizeof(node));
    novo->noBST = noBST;
    novo->prox = NULL;
    novo->ant = NULL;

    if(vazia(f)) {
        f->prim = f->ult = novo;
    } else {
        f->ult->prox = novo;
        novo->ant = f->ult;
        f->ult = novo;
    }
}

bst* dequeue(filaBST* f) {
    if(vazia(f)) {
        printf("Fila vazia.\n");
        return NULL;
    }
    node* prim = f->prim;
    bst* dequeueNode = prim->noBST;

    f->prim = prim->prox;

    if(f->ult == prim) { // só tinha um elemento na fila
        f->ult = NULL;
    }

    free(prim);

    return dequeueNode;
}

void destroiFilaBST(filaBST* f) {
    if(!f) return;

    node* n = f->prim;
    while (n != NULL) {
        f->prim = f->prim->prox;
        free(n);
        n = f->prim;
    }
    free(f);    
}