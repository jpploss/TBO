#include <stdio.h>
#include <stdlib.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char* argv[]) {
    if(argc == 1) {
        printf("Tamanha do array não especificado.\n");
        return 0;
    }

    int n = 0;
    sscanf(argv[1], "%d", &n);

    Item* itens = malloc(sizeof(Item)*n);
    for(int i = 0; i < n; i++) scanf("%d", (itens + i));

    sort(itens, 0, n);

    printf("\n");
    for(int i = 0; i < n; i++) printf("%d ", itens[i]);
    printf("\n\n");    

    free(itens);
    return 0;
}