#include "item.h"

void sort(Item *a, int lo, int hi) {
    if(hi - lo <= 0) return;

    for(int i = lo; i < hi-1; i++) {
        int idxMenor = i;
        for(int j = i+1; j < hi; j++) {
            if(less(a[j], a[idxMenor])) idxMenor = j;
        }
        exch(a[i], a[idxMenor]);
    }
}