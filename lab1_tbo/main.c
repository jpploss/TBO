#include "util.h"
#include <stdio.h>
#include <stdlib.h>

// https://docs.google.com/document/d/1sg-wGuBs1OEmNWeEjdfNAExDT-4OGqx_ZFIJIcRPbgs/edit?tab=t.0

int main() {
    int n = 100;

    vetAux* v = criaVet(n);

    for(int i = 2; i > 0; i = proxNaoMarcado(v, i))
        marcaMultiplos(v, i);
    
    imprimeNaoMarcados(v);
    desalocaVet(v);
    return 0;
}