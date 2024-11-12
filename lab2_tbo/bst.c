#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct _bst {
    int chave;
    bst* maior;
    bst* menor;
};

static int ehFolha(bst* b) {
    return (!b->maior) && (!b->menor);
}

bst* criaBST() {
    return NULL;
}

bst* insereBST(bst* b, int c) {
    if(b == NULL) {
        bst* nova = malloc(sizeof(bst));
        nova->chave = c;
        nova->maior = nova->menor = NULL;
        return nova;
    }

    if(c > b->chave) {
        b->maior = insereBST(b->maior, c);
    } else if (c < b->chave) {
        b->menor = insereBST(b->menor, c);
    }

    return b;
}

int alturaBST(bst* b) {
    if(!b) return -1;
    if(ehFolha(b)) return 0;

    int alturaEsq = 1, alturaDir = 1;

    if(b->maior) alturaEsq += alturaBST(b->maior);
    if(b->menor) alturaDir += alturaBST(b->menor);

    return (alturaDir > alturaEsq) ? alturaDir : alturaEsq;
}

void destroiBST(bst* b) {
    if(!b) return;

    destroiBST(b->maior);
    destroiBST(b->menor);
    free(b);
}