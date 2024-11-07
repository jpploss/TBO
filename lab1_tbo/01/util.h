#ifndef UTIL_H
#define UTIL_H

typedef struct _vetAux vetAux;

vetAux* criaVet(int n);

void marcaMultiplos(vetAux* v, int n);

int proxNaoMarcado(vetAux* v, int n);

void imprimeNaoMarcados(vetAux* v);

void desalocaVet(vetAux* v);

#endif