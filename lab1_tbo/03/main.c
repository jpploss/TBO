#include <stdio.h>
#include "pilha.h"

double fazOperacao(char op, double n1, double n2) {
    if(op == '*') return n1*n2;
    if(op == '+') return n1+n2;
    if(op == '-') return n1-n2;
    if(op == '/') return n1/n2;
}

int main() {
    char operadorLido, operador;
    double operandoLido;
    double operando1, operando2;
    double resultado;

    pilha* pilhaOperadores = criaPilha();
    pilha* pilhaOperandos = criaPilha();

    while(1) {
        if(scanf("%lf", &operandoLido)) {
            empilhaItem(pilhaOperandos, (void*)&operandoLido);
        } 
        
        else if(scanf("%c", &operadorLido)) {
            if(operadorLido == '.') break;
            else if(operadorLido == '(') continue;

            else if(operadorLido == ')') {
                operador = *((char*)desempilhaItem(pilhaOperadores));
                printf("-- %c\n", operador);
                operando1 = *((double*)desempilhaItem(pilhaOperandos));
                printf("-- %lf\n", operando1);
                operando2 = *((double*)desempilhaItem(pilhaOperandos));
                printf("-- %lf\n", operando2);

                resultado = fazOperacao(operador, operando2, operando1);
                printf("-- %lf\n", resultado);
                empilhaItem(pilhaOperandos, (void*)&resultado);
            }
            
            else empilhaItem(pilhaOperadores, (void*)&operadorLido);   
        }
    }
    printf("%lf\n", *((double*)desempilhaItem(pilhaOperandos)));

    return 1;
}