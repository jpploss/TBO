#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "str.h"
#include "suffix.h"

String* read_clean_input(FILE* input_file);

int main(int argc, char const *argv[]) {
    if(argc == 1) {
        printf("Nome do arquivo não passado na chamada do programa.\n");
        return EXIT_FAILURE;
    }
    FILE* input_file = fopen(argv[1], "r");
    if(input_file == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    String* s = read_clean_input(input_file);
    fclose(input_file);
    int s_len = s->len;
    // print_string(s);

    Suffix** sfxs = malloc(sizeof(Suffix*)*s_len);
    for(int i = 0; i < s_len; i++) sfxs[i] = create_suffix(s, i);
    // for(int i = 0; i < s_len; i++) { print_suffix(sfxs[i]); printf("\n"); }

    for(int i = 0; i < s_len; i++) destroy_suffix(sfxs[i]);
    free(sfxs);
    destroy_string(s);

    return 0;
}

String* read_clean_input(FILE* input_file) {
    int nCaracteres = 0;
    fscanf(input_file, "%d%*[^\n]%*c", &nCaracteres);
    fscanf(input_file, "%*[^\n]");
    fscanf(input_file, "%*c");
    char* s = malloc(sizeof(char)*(nCaracteres+1));
    char aux = 0;
    int count = 0;
    while((aux = getc(input_file)) != EOF) {
        if(isspace(aux)) {
            s[count] = ' ';
            count++;
            while(isspace(aux)) aux = getc(input_file);
            if(aux == EOF) continue;
        }    
        s[count] = aux;
        count++;
    }
    s[count] = '\0';
    String* realString = create_string(s);
    free(s);
    return realString;
}