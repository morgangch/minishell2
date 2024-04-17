/*
** EPITECH PROJECT, 2023
** day07 - my_strncat
** File description:
** func to cat strs
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0; i < nb && src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    return dest;
}
