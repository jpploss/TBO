#include <stdio.h>
#include <stdlib.h>
#include "util.h"

struct _vetAux {
    int* vet;
    int size;
};

vetAux* criaVet(int n) { // n = final do intervalo
    if(n <= 2) {
        printf("Número inválido.\n");
        return NULL;
    }
    
    vetAux* v = malloc(sizeof(vetAux));

    v->size = n - 1;
    v->vet = calloc(v->size, sizeof(int));

    return v;
}

void marcaMultiplos(vetAux* v, int n) {
    int fim = v->size + 1;
    for(int i = (n + 1); i <= fim; i++) {
        if(i % n == 0)
            v->vet[i - 2] = 1;
    }
}

int proxNaoMarcado(vetAux* v, int n) {
    int tam = v->size;
    int idxProx = n - 1;

    for(int i = idxProx; i < tam; i++) {
        if(v->vet[i] == 0) return i + 2;
    }
    return -1;
}

void imprimeNaoMarcados(vetAux* v) {
    for(int i = 0; i < v->size; i++) {
        if(v->vet[i] == 0)
            printf("%d ", i+2);
    }
    printf("\n");
}

void desalocaVet(vetAux* v) {
    if(!v) return;
    if(!v->vet) return;

    free(v->vet);
    free(v);
}