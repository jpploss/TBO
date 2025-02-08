#ifndef SUFFIX_H
#define SUFFIX_H

typedef struct _suffix Suffix;

Suffix* create_suffix(String* s, int i);

void destroy_suffix(Suffix* sfx);

void print_suffix(Suffix* sfx);

#endif