#ifndef SUFFIX_H
#define SUFFIX_H

typedef struct _suffix Suffix;
struct _suffix {
    String* str;
    int index;
    int size;
};

Suffix* create_suffix(String* s, int i, int sz);

void destroy_suffix(Suffix* sfx);

void print_suffix(Suffix* sfx);

#endif