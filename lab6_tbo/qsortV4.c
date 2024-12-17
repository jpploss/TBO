#include <stdlib.h>
#include <stdio.h>

// quick sort com CUTOFF para insertion sort + pivo sendo a mediana de três valores aleatórios do vetor

#define CUTOFF 10

static int medianaDe3(int *vet, int lo, int hi) {
    if((hi - lo + 1) < 3) return lo;

    int idx1 = lo + (rand() % (hi - lo + 1));
    int idx2 = lo + (rand() % (hi - lo + 1));
    int idx3 = lo + (rand() % (hi - lo + 1));

    if(vet[idx1] >= vet[idx2]) {
        if(vet[idx1] <= vet[idx3]) return idx1;
        else { // vet[idx1] > vet[idx3]
            if(vet[idx2] >= vet[idx3]) return idx2;
            return idx3;
        }
    } else { // vet[idx1] < vet[idx2]
        if(vet[idx1] >= vet[idx3]) return idx1;
        else { // vet[idx1] < vet[idx3]
            if(vet[idx2] <= vet[idx3]) return idx2;
            return idx3;
        }
    }
}

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

    int idx_med3 = medianaDe3(vet, lo, hi);

    int aux = vet[idx_med3];
    vet[idx_med3] = vet[lo];
    int pivo = vet[lo] = aux;
    
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