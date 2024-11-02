#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <math.h>

struct _vetAux {
    int bitmask; // bit 0: 2, bit 1: 3, ..., bit n-2: n
    int n
};

vetAux* criaVet(int n) { // n = final do intervalo
    vetAux* v = calloc(1, sizeof(vetAux));
    v->n = n;
    return v;
}

void marcaMultiplos(vetAux* v, int n) {
    for(int i = 2; i <= v->n; i++) {
        if(i % n == 0) {
            v->bitmask = v->bitmask | ((int) pow(2, (i-2))); // marca o bit correspondente ao número 'i'
        }
    }
}

int proxNaoMarcado(vetAux* v, int n) {
    
}

void imprimeNaoMarcados(vetAux* v) {
    
}

void desalocaVet(vetAux* v) {
    if(!v) return;
    free(v);
}