/*
** EPITECH PROJECT, 2023
** day0X - my_strcapitalize
** File description:
** Func to capitalize str
*/

#include "my.h"

char my_charupcase(char c)
{
    char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *alpha2 = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; alpha[i] != '\0'; i++) {
        if (c == alpha2[i])
            c = alpha[i];
    }
    return c;
}

char *my_strupcase(char *str)
{
    int comp;

    for (int i = 0; str[i] != '\0'; i++) {
        comp = my_char_isupper(str[i]);
        if (comp == 0)
            str[i] = my_charupcase(str[i]);
    }
    return str;
}
