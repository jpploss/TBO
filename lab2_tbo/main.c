#include <stdio.h>
#include "bst.h"
#include <time.h>
#include <stdlib.h>

// https://docs.google.com/document/d/11JgrQxJ9loAbhdFQNmkOK7vhNXFqfaXMsP5oQEkYDcc/edit?tab=t.0?

int main() {
    bst* b = criaBST();
    srand(time(NULL));
    
    int rodadas = 10;
    int somaAlturas = 0, alturaAtual;
    for(int r = 0; r < 10; r++) {
        for(int i = 0; i < 1000000; i++) b = insereBST(b, rand());
        alturaAtual = alturaBST(b);
        printf("altura para r = %d: %d\n", r, alturaAtual);

        somaAlturas += alturaAtual;
    }

    printf("media: %f\n", ((float)somaAlturas) / rodadas);

    destroiBST(b);

    return 0;
}