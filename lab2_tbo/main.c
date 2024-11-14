#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bst.h"
#include "pilhaBST.h"

// https://docs.google.com/document/d/11JgrQxJ9loAbhdFQNmkOK7vhNXFqfaXMsP5oQEkYDcc/edit?tab=t.0?

int main() {
    bst* b = criaBST();

// ----- PARA A PARTE 2 DO LAB:
    // srand(time(NULL));
    
    // int rodadas = 10;
    // int somaAlturas = 0, alturaAtual;
    // for(int r = 0; r < 10; r++) {
    //     for(int i = 0; i < 1000000; i++) b = insereBST(b, rand());
    //     alturaAtual = alturaBST(b);
    //     printf("altura para r = %d: %d\n", r, alturaAtual);

    //     somaAlturas += alturaAtual;
    // }

    // printf("media: %f\n", ((float)somaAlturas) / rodadas);
// -----

// ----- PARA A PARTE 3 DO LAB:
    b = insereBST(b, 6);
    b = insereBST(b, 7);
    b = insereBST(b, 2);
    b = insereBST(b, 1);
    b = insereBST(b, 4);
    b = insereBST(b, 3);
    b = insereBST(b, 5);
    b = insereBST(b, 9);
    b = insereBST(b, 8);

    

    // preOrdem(b, visita);
    // emOrdem(b, visita);
    // posOrdem(b, visita);

    // semRecPreOrdem(b, visita);
    // semRecEmOrdem(b, visita);
    semRecPosOrdem(b, visita);
// -----

    // printf("\naltura: %d\n", alturaBST(b));
    destroiBST(b);

    return 0;
}