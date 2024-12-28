#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Bottom-up quick sort não recursivo com cutoff e mediana de 3

#define CUTOFF 12

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

int stackSize = 0;
int topo = 0;
int* stack = NULL;

void push(int item) {
    if(stack == NULL) return;
    if(topo == stackSize) return;

    stack[topo++] = item;
}

int pop() {
    if(stack == NULL) return -1;
    if(topo == 0) return -1;

    return stack[--topo];
}

int isEmpty() {
    return topo == 0;
}

void sort(int *vet, int lo, int hi) {
    int N = hi - lo + 1;

    stackSize = (int) log2(N)*2;
    stack = malloc(sizeof(int)*stackSize);

    push(hi); push(lo);
    while (!isEmpty()) {

        int loAtual = pop(), hiAtual = pop();

        if(loAtual >= hiAtual) continue;
        else if((hiAtual - loAtual + 1) <= CUTOFF) { 
            insertion_sort(vet, loAtual, hiAtual);
            continue;;
        }
        
        int i = loAtual, j = hiAtual + 1;

        int idx_med3 = medianaDe3(vet, lo, hi);
        int aux = vet[idx_med3];
        vet[idx_med3] = vet[lo];
        int pivo = vet[lo] = aux;

        while (1) {
            
            while(vet[++i] <= pivo)
                if(i == hiAtual) break;
            while(vet[--j] >= pivo)
                if(j == loAtual) break;
            
            if(j <= i) {
                vet[loAtual] = vet[j];
                vet[j] = pivo;
                break;
            }

            int aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
        }

        if(j - loAtual > hiAtual - j) {
            push(j - 1); push(loAtual);
            push(hiAtual); push(j + 1);
        } else {
            push(hiAtual); push(j + 1);
            push(j - 1); push(loAtual);
        }
        
    }
    
    free(stack);
}