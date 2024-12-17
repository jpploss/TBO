#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(int *vet, int lo, int hi);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Parâmetros incorretos.\n");
        return 1;
    }

    int tam = atoi(argv[1]);
    FILE* arq = fopen(argv[2], "r");

    int* vet = malloc(sizeof(int)*tam);
    for(int i = 0; i < tam; i++) fscanf(arq, "%d", (vet + i));
    
    clock_t inicio = clock();
    sort(vet, 0, tam-1);
    clock_t fim = clock();
    double tempoTotal = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("N = %d: %.03fs\n", tam, tempoTotal);

    for(int i = 0; i < tam; i++) printf("%d ", vet[i]);
    printf("\n");

    free(vet);
    fclose(arq);

    return 0;
}