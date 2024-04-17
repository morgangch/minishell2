/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(const char *src)
{
    char *dupe = malloc((my_strlen(src) + 1) * sizeof(char));

    my_strcpy(dupe, src);
    return dupe;
}
