#include <stdio.h>
#include <stdlib.h>
#include "str.h"
#include "suffix.h"

Suffix* create_suffix(String* s, int i, int sz) {
    Suffix* sfx = malloc(sizeof(Suffix));
    sfx->index = i;
    sfx->str = s;
    sfx->size = sz;
    return sfx;
}

void destroy_suffix(Suffix* sfx) {
    if(sfx) free(sfx);
}

void print_suffix(Suffix* sfx) {
    for(int i = sfx->index; sfx->str->c[i] != '\0'; i++) {
        printf("%c", sfx->str->c[i]);
    }
    printf(" %d", sfx->size);
}
