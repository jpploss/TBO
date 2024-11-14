#ifndef BST_H
#define BST_H

typedef struct _bst bst;

bst* criaBST();

bst* insereBST(bst* b, int c);

int alturaBST(bst* b);

void destroiBST(bst* b);

void visita(bst* b);

void preOrdem(bst* b, void (*vista)(bst*));
void semRecPreOrdem(bst* b, void (*vista)(bst*));

void emOrdem(bst* b, void (*vista)(bst*));
void semRecEmOrdem(bst* b, void (*vista)(bst*));

void posOrdem(bst* b, void (*vista)(bst*));
void semRecPosOrdem(bst* b, void (*vista)(bst*));

#endif