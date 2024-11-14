#include <stdio.h>
#include <stdlib.h>
#include "pilhaBST.h"

struct _pilhaBST {
    bst* pilha[TAM];
    int topo;
};

pilhaBST* criaPilhaBST() {
    return calloc(1, sizeof(pilhaBST));
}

void push(pilhaBST* p, bst* node) {
    if(p->topo == TAM) {
        printf("Pilha cheia.\n");
        return;
    }

    p->pilha[p->topo] = node;
    p->topo += 1;
}

bst* pop(pilhaBST* p) {
    if(p->topo == 0) {
        printf("Pilha vazia.\n");
        return NULL;
    }

    p->topo -= 1;
    return p->pilha[p->topo];
}

void destroiPilhaBST(pilhaBST* p) {
    if(p) free(p);
}