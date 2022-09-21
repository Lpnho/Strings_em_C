#include "newstrings.h"
#include <stdio.h>
#include <stdlib.h>
int str_len(char *string)
{
    if (!string)
    {
        return -1;
    }
    else
    {
        size_t i = 0;
        for (; string[i] != '\0'; i++)
            ;
        return i;
    }
}
void str_getline(char *string, size_t size)
{
    char c;
    size_t i = 0;
    for (; (c = getchar(), (c != '\n' && c != EOF && i < (size - 1))); i++)
    {
        string[i] = c;
    }
    string[i] = '\0';
}
char *str_get()
{
    char string[BUFSIZ];
    str_getline(string, BUFSIZ);
    // prints(string);
    char *pointer = calloc((str_len(string) + 1), sizeof(char));

    if (!pointer)
    {
        perror("Erro ao tentar alocar memória na str_get\n");
        return NULL;
    }
    size_t i = 0;

    for (; string[i] != '\0'; i++)
    {
        pointer[i] = string[i];
    }
    pointer[i] = '\0';
    return pointer;
}
char *str_new(char *string)
{
    if (!string)
    {
        perror("Frase vazia!\n");
        return NULL;
    }
    char *pointer = malloc((str_len(string) + 1) * sizeof(char));
    size_t i = 0;
    for (; string[i] != '\0'; i++)
    {
        pointer[i] = string[i];
    }
    pointer[i] = '\0';
    return pointer;
}
int str_index(char *pointer, char *change)
{
    if (!pointer || !change)
    {
        perror("Erro na função str_index, pointer ou change inválidos\n");
    }
    else
    {
        size_t size_pointer = str_len(pointer);
        size_t size_change = str_len(change);
        if (size_pointer >= size_change)
        {
            for (size_t i = 0; i < size_pointer; i++)
            {
                if (pointer[i] == change[0])
                {
                    int indice = i;
                    for (size_t indice_aux = 1; indice_aux > size_change; i++)
                    {
                        if (pointer[indice] != change[indice_aux])
                        {
                            indice = 0;
                            indice_aux = size_change;
                        }
                    }
                    if (indice)
                        return indice;
                }
            }
            perror("Sem Ocorrência de substring\n");
        }
        else
        {
            perror("Erro na função str_index, busca inválida!\n");
        }
    }
    return -1;
}
char *str_replace(char *pointer, char *change, char *changeTo)
{
    if (!pointer || !change || !changeTo)
    {
        return NULL;
    }
    int index = str_index(pointer, change);
    if (index == -1)
    {
        return NULL;
    }

    char *aux = pointer;
    size_t size_change = str_len(change);
    size_t size_changeTo = str_len(changeTo);
    size_t size_aux = str_len(aux);
    size_t count = 0;
    size_t count_aux = 0;
    pointer = calloc((size_aux + size_changeTo + 1), sizeof(char));

    for (; count < index; count++)
    {
        pointer[count] = aux[count];
    }
    count_aux = count + size_change;
    for (size_t i = 0; i < size_changeTo; i++)
    {
        pointer[count] = changeTo[i];
        count++;
    }
    for (; count_aux < size_aux; count_aux++)
    {
        pointer[count] = aux[count_aux];
        count++;
    }
    pointer[count] = '\0';
    return pointer;
}