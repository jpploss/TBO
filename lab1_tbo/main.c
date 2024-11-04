#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// https://docs.google.com/document/d/1sg-wGuBs1OEmNWeEjdfNAExDT-4OGqx_ZFIJIcRPbgs/edit?tab=t.0

int main() {
    clock_t inicio = clock();

    int n = 330;
    vetAux* v = criaVet(n);
    for(int i = 2; i > 0; i = proxNaoMarcado(v, i)) {
        marcaMultiplos(v, i);
    }
    // imprimeNaoMarcados(v);
    desalocaVet(v);

    clock_t fim = clock();
    double tempoTotal = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", tempoTotal);

    return 0;
}