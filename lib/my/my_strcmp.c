/*
** EPITECH PROJECT, 2023
** day06 - my_strncmp
** File description:
** Func to search a string in another one
*/

#include <stdlib.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}
