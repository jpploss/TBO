#include <stdio.h>
#include <stdlib.h>

extern void sort(int *a, int lo, int hi);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Parâmetros incorretos.\n");
        return 1;
    }

    int tam = atoi(argv[1]);
    FILE* arq = fopen(argv[2], 'r');

    int* vet = malloc(sizeof(int)*tam);
    for(int i = 0; i < tam; i++) fscanf(arq, "%d", (vet + i));

    sort(vet, 0, tam);

    return 0;
}