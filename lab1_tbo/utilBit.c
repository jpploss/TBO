#include <stdio.h>
#include <stdlib.h>
#include "util.h"

struct _vetAux {
    int vet;
};

vetAux* criaVet(int n) { // n = final do intervalo
    return calloc(1, sizeof(vetAux));
}

void marcaMultiplos(vetAux* v, int n) {
    
}

int proxNaoMarcado(vetAux* v, int n) {
    
}

void imprimeNaoMarcados(vetAux* v) {

}

void desalocaVet(vetAux* v) {
    if(!v) return;
    free(v);
}