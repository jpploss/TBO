#include <stdlib.h>
#include <stdio.h>

// merge clássico

void merge(int* vet, int* aux, int lo, int mid, int hi) {
    for(int i = lo; i <= hi; i++) aux[i] = vet[i];
    
    int left = lo, right = mid+1; // left: índice que percorre o vetor da esquerda. | right: índice que percorre o vetor da direita.
    // vetor da esquerda: [lo, mid]
    // vetor da direita: [mid+1, hi]

        for(int i = lo; i <= hi; i++) {
        if(left > mid) {
            // se o vetor da esquerda acabou, termina o merge com os elementos do vetor da direita.
            vet[i] = aux[right++];
        }
        else if(right > hi) {
            // se o vetor da direita acabou, termina o merge com os elementos do vetor da esquerda.
            vet[i] = aux[left++];
        } 
        else if(aux[left] <= aux[right]) {
            vet[i] = aux[left++];
        }
        else {
            vet[i] = aux[right++];
        }
    }
}

void merge_sort(int* vet, int* aux, int lo, int hi) {
    if(hi <= lo) return;

    int mid = (lo + (hi-lo)/2);
    merge_sort(vet, aux, lo, mid);
    merge_sort(vet, aux, mid+1, hi);
    merge(vet, aux, lo, mid, hi);
}

void sort(int *vet, int lo, int hi) { // [lo, hi]
    int* aux = malloc(sizeof(int)*(hi+1));
    merge_sort(vet, aux, lo, hi);
    free(aux);
}