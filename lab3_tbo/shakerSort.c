#include "item.h"
#include <stdio.h>

/*
O shaker sort também ́e chamado de bubble sort bidirecional, porque o array ́e percorrido nas
duas direções a cada passada. Em alguns casos, o shaker sort  ́e mais rápido que o bubble sort,
em particular por fazer melhor uso da localidade de cache.
*/

void sort(Item *a, int lo, int hi) {
    if(hi - lo <= 0) return;

    printf("Rodando shaker sort.\n");

    for(int i = lo; i < hi/2; i++) { // como a ordenação acontece nos dois sentidos, ir até a metade é suficiente
        
        for(int j = 0; j < hi - i - 1; j++) { // percorre da esquerda para a direita ordenando os maiores
            compexch(a[j], a[j+1]);
        }

        for(int j = hi - i - 2; j > i; j--) { // percorre da direita para a esquerda ordenando os menores
            compexch(a[j-1], a[j]);
        }
    }
}