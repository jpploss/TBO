#include <stdio.h>
#include "circulo.h"
#include "time.h"

// https://docs.google.com/document/d/1sg-wGuBs1OEmNWeEjdfNAExDT-4OGqx_ZFIJIcRPbgs/edit?tab=t.0

int main() {
    clock_t inicio = clock();
    int n = 100000000, m = 10;

    circulo* c = criaCirculo(n, m);
    int lider = achaLider(c);
    // printf("%d\n", lider);

    liberaCirculo(c);
    clock_t fim = clock();
    double tempoTotal = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo decorrido para n = %d: %f seconds\n", n, tempoTotal);

    return 0;
}