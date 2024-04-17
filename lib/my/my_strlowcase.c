/*
** EPITECH PROJECT, 2023
** day0X - my_strcapitalize
** File description:
** Func to capitalize str
*/

#include "my.h"

char my_charlowcase(char c)
{
    char *alpha2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *alpha = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; alpha[i] != '\0'; i++) {
        if (c == alpha2[i])
            c = alpha[i];
    }
    return c;
}

char *my_strlowcase(char *str)
{
    int comp;

    for (int i = 0; str[i] != '\0'; i++) {
        comp = my_char_islower(str[i]);
        if (comp == 0)
            str[i] = my_charlowcase(str[i]);
    }
    return str;
}
