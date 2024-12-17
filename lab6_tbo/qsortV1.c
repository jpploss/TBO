#include <stdlib.h>
#include <stdio.h>

// quick sort clássico

void sort(int *vet, int lo, int hi) { // [lo, hi]
    if(lo >= hi) return;

    int pivo = vet[lo];
    int i = lo, j = hi+1;

    while(1) {
        while(vet[++i] <= pivo)
            if(i == hi) break; 

        while(vet[--j] >= pivo)
            if(j == lo) break; 

        if(j <= i) {
            int aux = vet[j];
            vet[j] = pivo;
            vet[lo] = aux;
            break;
        }

        int aux = vet[j];
        vet[j] = vet[i];
        vet[i] = aux;
    }

    sort(vet, lo, j-1);
    sort(vet, j+1, hi);
}