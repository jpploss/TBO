#ifndef PILHA_H
#define PILHA_H

typedef struct _pilha pilha;

pilha* criaPilha();

void empilhaItem(pilha* p, void* item);

void* desempilhaItem(pilha* p);

void liberaPilha(pilha* p);

#endif