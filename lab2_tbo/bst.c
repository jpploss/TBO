#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "pilhaBST.h"
#include "filaBST.h"


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

void visita(bst* b) {
    printf("%c\n", ((char)b->chave - 1) + 'A');
    return;
}

void preOrdem(bst* b, void (*vista)(bst*)) {
    if(b == NULL) return;

    vista(b);
    preOrdem(b->menor, visita);
    preOrdem(b->maior, visita);
}

void semRecPreOrdem(bst* b, void (*vista)(bst*)) {
    if(b == NULL) return;

    pilhaBST* p = criaPilhaBST();
    bst* node = b;
    push(p, node);
    while(!vaziaPilhaBST(p)) {
        node = pop(p);
        visita(node);

        if(node->maior) push(p, node->maior);
        if(node->menor) push(p, node->menor);
    }

    destroiPilhaBST(p);
}

void emOrdem(bst* b, void (*vista)(bst*)) {
    if(b == NULL) return;

    emOrdem(b->menor, visita);
    vista(b);
    emOrdem(b->maior, visita);
}

void semRecEmOrdem(bst* b, void (*vista)(bst*)) {
    if(b == NULL) return;

    pilhaBST* p = criaPilhaBST();
    bst* node = b;

    while(!vaziaPilhaBST(p) || node != NULL) {
        if(node == NULL) {
            node = pop(p);
            visita(node);
            node = node->maior;
        } else {
            push(p, node);
            node = node->menor;
        }
    }

    destroiPilhaBST(p);
}

void posOrdem(bst* b, void (*vista)(bst*)) {
    if(b == NULL) return;

    posOrdem(b->menor, visita);
    posOrdem(b->maior, visita);
    vista(b);
}

void semRecPosOrdem(bst* b, void (*vista)(bst*)) {
    if(b == NULL) return;

    pilhaBST* p = criaPilhaBST();
    bst* node = b;
    bst* ultimoVisitado = NULL;
    while (!vaziaPilhaBST(p) || node != NULL) {
        if(node != NULL) {
            push(p, node);
            node = node->menor;
        } else {
            bst* topo = retornaTopo(p);
            if(topo->maior && ultimoVisitado != topo->maior) node = topo->maior;
            else {
                ultimoVisitado = pop(p);
                visita(ultimoVisitado);
                node = NULL;
            }           
        }
    }
    
    destroiPilhaBST(p);
}

void semRecEmNivel(bst* b, void (*vista)(bst*)) {
    filaBST* f = criaFilaBST();

    bst* nodeAtual = b;
    enqueue(f, nodeAtual);

    while (!vazia(f)) {
        nodeAtual = dequeue(f);
        if(nodeAtual->menor) enqueue(f, nodeAtual->menor);
        if(nodeAtual->maior) enqueue(f, nodeAtual->maior);

        visita(nodeAtual);
    }
    
    destroiFilaBST(f);
}