#ifndef FILABST_H
#define FILABST_H

typedef struct _bst bst;

typedef struct _filaBST filaBST;

filaBST* criaFilaBST();

void enqueue(filaBST* f, bst* noBST);

bst* dequeue(filaBST* f);

int vazia(filaBST* f);

void destroiFilaBST(filaBST* f);

#endif