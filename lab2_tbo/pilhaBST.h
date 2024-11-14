#ifndef PILHABST_H
#define PILHABST_H

#define TAM 100

typedef struct _bst bst;

typedef struct _pilhaBST pilhaBST;

pilhaBST* criaPilhaBST();

int vaziaPilhaBST(pilhaBST* p);

void push(pilhaBST* p, bst* node);

bst* pop(pilhaBST* p);

bst* retornaTopo(pilhaBST* p);

void destroiPilhaBST(pilhaBST* p);

#endif