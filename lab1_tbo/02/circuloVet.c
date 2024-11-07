#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

struct _circulo {
    char* circulo;
    int n, m;
};

circulo* criaCirculo(int n, int m) {
    circulo* c = malloc(sizeof(circulo));

    c->m = m;
    c->n = n;
    c->circulo = calloc(n, sizeof(char));

    return c;
}

int achaLider(circulo* c) {
    int posicaoPessoaAtual = 0;
    int m = c->m;
    int n = c->n;

    int restantes = n;
    while (restantes > 1) {
        
        for(int i = 1; i < m; i++) {
            posicaoPessoaAtual = (posicaoPessoaAtual + 1) % n;
            while(c->circulo[posicaoPessoaAtual]) posicaoPessoaAtual = (posicaoPessoaAtual + 1) % n; // acha a proxima posição não marcada
        }

        c->circulo[posicaoPessoaAtual] = 1;
        while(c->circulo[posicaoPessoaAtual]) posicaoPessoaAtual = (posicaoPessoaAtual + 1) % n; // acha a proxima posição não marcada

        restantes--;
    }
    return posicaoPessoaAtual + 1;
}

void liberaCirculo(circulo* c) {
    if(!c) return;
    if(!c->circulo) return;
    free(c->circulo);
    free(c);
}