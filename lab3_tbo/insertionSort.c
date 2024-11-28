#include "item.h"
#include <stdio.h>

void sort(Item *a, int lo, int hi) {
    if(hi - lo <= 0) return;

    printf("Rodando insertion sort.\n");

    for(int i = lo+1; i < hi; i++) {
        for(int j = i; j > lo; j--) {
            if(!less(a[j], a[j-1])) break;
            exch(a[j], a[j-1]);
        }
    }
}