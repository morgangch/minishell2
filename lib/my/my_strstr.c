/*
** EPITECH PROJECT, 2023
** day06 - my_strstr
** File description:
** Func to find a str in a str
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == to_find[i])
            i++;
        if (to_find[i] == '\0')
            return str;
        str++;
    }
    return NULL;
}
