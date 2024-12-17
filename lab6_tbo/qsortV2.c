#include <stdlib.h>
#include <stdio.h>

// quick sort com cutoff para insertion sort

#define CUTOFF 10

void insertion_sort(int* vet, int lo, int hi) {
    if(hi <= lo) return;

    for(int i = lo+1; i <= hi; i++) {
        for(int j = i; j > lo; j--) {
            if(vet[j] < vet[j-1]) { // se fosse '<=' em vez de '<', a estabilide seria quebrada
                int temp = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = temp;
            } else break;
        }
    }
}

void sort(int *vet, int lo, int hi) { // [lo, hi]
    if(lo >= hi) return;

    if((hi - lo + 1) <= CUTOFF) { 
        insertion_sort(vet, lo, hi);
        return;
    }

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