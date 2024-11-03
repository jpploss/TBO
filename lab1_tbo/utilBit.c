#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <math.h>

struct _vetAux {
    int bitmask; // bit 0: 2, bit 1: 3, ..., bit n-2: n
    int fim;
};

vetAux* criaVet(int n) { // n = final do intervalo
    if((n - 1) > (sizeof(int)*8)) {
        printf("Limite excedido, o número máximo é %ld.\n", sizeof(int)*8 + 1);
        exit(EXIT_FAILURE);
    }
    vetAux* v = calloc(1, sizeof(vetAux));
    v->fim = n;
    return v;
}

void marcaMultiplos(vetAux* v, int n) {
    if(n > v->fim) return;
    int bitDeN = n - 2;
    int mask = (int) pow(2, bitDeN+1);
    for(int i = n + 1; i <= v->fim; i++) {
        if(i % n == 0) {
            v->bitmask = v->bitmask | mask; // marca o bit correspondente ao número 'i'
        }
        mask *= 2;
    }
}

int proxNaoMarcado(vetAux* v, int n) {
    if(n > v->fim) return -1;

    int bitDeN = n - 2;
    int mask = (int) pow(2, bitDeN+1);

    for(int b = bitDeN+1; b <= v->fim-2; b++) {
        if( !(v->bitmask & mask) )
            return (b+2);
        mask *= 2;
    }
    return -1;
}

void imprimeNaoMarcados(vetAux* v) {
    int mask = 1;
    for(int i = 2; i < v->fim; i++) {
        if( !(mask & v->bitmask) ) {
            printf("%d ", i);
        }
        mask *= 2;
    }
    printf("\n");
}

void desalocaVet(vetAux* v) {
    if(!v) return;
    free(v);
}