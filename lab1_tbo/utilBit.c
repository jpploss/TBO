#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <math.h>

struct _vetAux {
    char* bitmask; // bit 0: 2, bit 1: 3, ..., bit n-2: n
    int fim;
};

vetAux* criaVet(int n) { // n = final do intervalo
    vetAux* v = malloc(sizeof(vetAux));
    v->fim = n;
    int bitsNecessarios = n - 1;
    int bytes = (bitsNecessarios + 7)/8;
    v->bitmask = calloc(bytes, sizeof(char));
    return v;
}

void marcaMultiplos(vetAux* v, int n) {
    if(n > v->fim) return;
    for(unsigned long int i = ((unsigned long int) n)*((unsigned long int) n); i <= v->fim; i+=n) {
        int bitDeI = i - 2;
        int byteIdx = bitDeI / 8;
        int bitDoByte = bitDeI % 8;
        char mask = 1 << bitDoByte;
        v->bitmask[byteIdx] |= mask;
    }
}

int proxNaoMarcado(vetAux* v, int n) {
    if(n > v->fim) return -1;

    for(int i = n + 1; i <= v->fim; i++) {
        int bitDeI = i - 2; 
        int byteIdx = bitDeI / 8;
        int bitDoByte = bitDeI % 8;
        char mask = 1 << bitDoByte;

        if( !(v->bitmask[byteIdx] & mask) ) {
            return i;
        }
    }

    return -1;
}

void imprimeNaoMarcados(vetAux* v) {
    for(int i = 2; i <= v->fim; i++) {
        int bitDeI = i - 2; 
        int byteIdx = bitDeI / 8;
        int bitDoByte = bitDeI % 8; 

        char mask = 1 << bitDoByte;

        if( !(v->bitmask[byteIdx] & mask) ) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void desalocaVet(vetAux* v) {
    if(!v) return;
    if(!v->bitmask) return;
    free(v->bitmask);
    free(v);
}