#ifndef CIRCULO_H
#define CIRCULO_H

typedef struct _circulo circulo;

circulo* criaCirculo(int n, int m);

int achaLider(circulo* c);

void liberaCirculo(circulo* c);

#endif