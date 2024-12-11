#include <stdio.h>
#include <stdlib.h>

// Bottom-up merge sort não recursiva:. A ideia é dividir o vetor em
// subvetores de 2, 4, 8, ... e usar o merge neles.

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

int min(int a, int b) {
    return (a < b) ? a : b;
}

void sort(int *vet, int lo, int hi) {
    int N = hi - lo + 1;
    int* aux = malloc(sizeof(int)*N);

    for(int tamSubvet = 1; tamSubvet < N; tamSubvet *= 2) {
        int inicioUltimoSubVet = N - tamSubvet + 1;
        for(int inicio = 0; inicio < inicioUltimoSubVet; inicio += tamSubvet*2) {
            int fim = inicio + tamSubvet*2 - 1;
            int mid = (inicio + fim)/2;
            merge(vet, aux, inicio, mid, min(fim, hi));
        }
    }
    free(aux);
}