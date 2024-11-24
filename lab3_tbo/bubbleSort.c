#include "item.h"
#include <stdio.h>

void sort(Item *a, int lo, int hi) {
    if(hi - lo <= 0) return;

    printf("\nRodando bubble sort.\n");

    for(int i = lo; i < hi-1; i++) {
        for(int j = 0; j < hi - i - 1; j++) {
            compexch(a[j], a[j+1]);
        }
    }
}