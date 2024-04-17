/*
** EPITECH PROJECT, 2023
** day0X - my_strcapitalize
** File description:
** Func to capitalize str
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int comp;

    for (int i = 0; str[i] != '\0'; i++) {
        comp = my_char_isupper(str[i]);
        if (comp == 0 && ((str[i - 1] >= 0 && str[i - 1] <= 64) || i == 0))
            str[i] = my_charupcase(str[i]);
        if (comp == 1 && (str[i - 1] >= 65) && i > 0)
            str[i] = my_charlowcase(str[i]);
    }
    return str;
}
