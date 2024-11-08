#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct _node node;

struct _node {
    void* item;
    node* prox;
    node* ant;
};


struct _pilha {
    node* prim;
    node* ult;    
};

pilha* criaPilha() {
    pilha* p = malloc(sizeof(pilha));
    p->prim = NULL;
    p->ult = NULL;
    return p;
}

void empilhaItem(pilha* p, void* item) {
    node* novo = malloc(sizeof(node));
    novo->prox = NULL;
    novo->ant = NULL;
    novo->item = item;

    if(p->prim == NULL) // pilha vazia
        p->prim = p->ult = novo;
    
    else {
        p->ult->prox = novo;
        novo->ant = p->ult;
        p->ult = novo;
    }
}

void* desempilhaItem(pilha* p) {
    if(p->ult == NULL) return NULL; // pilha vazia

    void* item = p->ult->item;

    node* noASerRemovido = p->ult;
    p->ult = p->ult->ant;
    if(p->ult) p->ult->prox = NULL;
    else p->prim = NULL; // pilha foi esvaziada

    free(noASerRemovido);

    return item;
}

void liberaPilha(pilha* p) {
    if(!p) return;

    if(p->prim == NULL) free(p);
    else {
        node* atual = p->prim;
        while (atual) {
            p->prim = p->prim->prox;
            free(atual);
            atual = p->prim;
        }
        free(p);
    }
}
