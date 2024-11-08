#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

// n1 <op> n2
double fazOperacao(char op, double n1, double n2) {    
    if(op == '*') return n1 * n2;
    if(op == '+') return n1 + n2;
    if(op == '-') return n1 - n2;
    if(op == '/') return n1 / n2;
}

int main() {
    char expressao[101];
    scanf("%[^\n]", expressao);
    char* expressaoSeparada = strtok(expressao, " ");

    pilha* pilhaNumeros = criaPilha();
    pilha* pilhaOperacoes = criaPilha();
    char operacaoLida;
    double numeroLido;
    double* nHeap;
    char* oHeap;

    while(expressaoSeparada) {
        if(sscanf(expressaoSeparada, "%lf", &numeroLido)) {
            nHeap = malloc(sizeof(double));
            *nHeap = numeroLido;
            empilhaItem(pilhaNumeros, (void*)nHeap);
        } 
        else {
            sscanf(expressaoSeparada, "%c", &operacaoLida);

            if(operacaoLida == ')') {
                double* n1 = (double*)desempilhaItem(pilhaNumeros);
                double* n2 = (double*)desempilhaItem(pilhaNumeros);
                char* operacao = (char*)desempilhaItem(pilhaOperacoes);

                nHeap = malloc(sizeof(double));
                *nHeap = fazOperacao(*operacao, *n2, *n1);
                empilhaItem(pilhaNumeros, nHeap);

                free(n1);
                free(n2);
                free(operacao);
            } 
            
            else if(operacaoLida != '('){
                oHeap = malloc(sizeof(char));
                *oHeap = operacaoLida;
                empilhaItem(pilhaOperacoes, oHeap);
            }
        }
        expressaoSeparada = strtok(NULL, " ");
    }
    
    double* resultado = (double*) desempilhaItem(pilhaNumeros);
    printf("Resultado: %.02lf\n", *resultado);
    free(resultado);
    free(pilhaNumeros);
    free(pilhaOperacoes); 

    return 0;
}