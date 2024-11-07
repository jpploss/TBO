#include <stdio.h>
#include "circulo.h"

int main() {

    int n = 5, m = 5;

    circulo* c = criaCirculo(n, m);
    printf("%d\n", achaLider(c));

    liberaCirculo(c);

    return 0;
}