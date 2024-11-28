#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"

// https://docs.google.com/document/d/1tJPlL2nrLqV7jWZIIWgV1UjbmRoW0ld5rBrMppAp8dY/edit?usp=sharing

extern void sort(Item *a, int lo, int hi);

int main(int argc, char* argv[]) {

    int n = 0;
    scanf("%d", &n);

    Item* itens = malloc(sizeof(Item)*n);
    for(int i = 0; i < n; i++) scanf("%d", (itens + i));

    clock_t inicio = clock();

    sort(itens, 0, n);

    clock_t fim = clock();
    double tempoTotal = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo decorrido para N = %d: %f seconds\n\n", n, tempoTotal);

    // printf("\n");
    // for(int i = 0; i < n; i++) printf("%d ", itens[i]);
    // printf("\n\n");    

    free(itens);
    return 0;
}