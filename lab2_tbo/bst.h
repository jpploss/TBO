#ifndef BST_H
#define BST_H

typedef struct _bst bst;

bst* criaBST();

bst* insereBST(bst* b, int c);

int alturaBST(bst* b);

void destroiBST(bst* b);

#endif