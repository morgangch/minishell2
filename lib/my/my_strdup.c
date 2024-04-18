/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(const char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
