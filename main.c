#include <stdio.h>
#include <stdlib.h>
#include "newstrings.h"
// REPLACEALL   (*)
// TOUPPERCASE  (*)
// TOLOWERCASE  (*)
// REPLACE                      -- IMPLEMENTADO
// LENGTH                       -- IMPLEMENTADO
// GETS                         -- IMPLEMENTADO 

int main(void)
{
    char *string = str_get();
    char *search = str_get();
    char *changeTo = str_get();

    char *novastring = str_replace(string, search, changeTo);
    prints(novastring);

    free(novastring);
    free(string);
    free(search);
    free(changeTo);
    
    return 0;
}
