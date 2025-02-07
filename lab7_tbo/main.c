#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "str.h"

String* leELimpaEntrada(FILE* arqEntrada);

int main(int argc, char const *argv[]) {
    if(argc == 1) {
        printf("Nome do arquivo não passado na chamada do programa.\n");
        return EXIT_FAILURE;
    }
    FILE* arqEntrada = fopen(argv[1], "r");
    if(arqEntrada == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    String* s = leELimpaEntrada(arqEntrada);
    print_string(s);

    destroy_string(s);

    return 0;
}

String* leELimpaEntrada(FILE* arqEntrada) {
    int nCaracteres = 0;
    fscanf(arqEntrada, "%d%*[^\n]%*c", &nCaracteres);
    fscanf(arqEntrada, "%*[^\n]");
    fscanf(arqEntrada, "%*c");
    char* s = malloc(sizeof(char)*nCaracteres);
    char aux = 0;
    int count = 0;
    while((aux = getc(arqEntrada)) != EOF) {
        if(isspace(aux)) {
            s[count] = ' ';
            count++;
            while(isspace(aux)) aux = getc(arqEntrada);
            if(aux == EOF) continue;
        }    
        s[count] = aux;
        count++;
    }

    s[count] = '\0';
    String* realString = create_string(s);
    printf("%d %d %d\n", count, (int)strlen(s), realString->len);
    free(s);
    return realString;
}