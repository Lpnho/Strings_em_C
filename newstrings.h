#ifndef STRINGS_H
#define STRINGS_H
// Libs
#include <stdlib.h>
#include <stdio.h>
// Prototipos
void str_getline(char *string, size_t size);
int str_len(char *string);
int str_index(char *pointer, char *change);
char *str_replace(char *pointer, char *change, char *changeTo);
char *str_get();
char *str_new(char *string);
// Macros
#define prints(s) printf("%s\n", s)
#define printi(i) printf("%i\n", i)

#endif