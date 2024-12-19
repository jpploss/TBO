#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Bottom-up quick sort não recursivo

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
        
        int i = loAtual, j = hiAtual + 1, pivo = vet[loAtual];
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