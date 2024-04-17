/*
** EPITECH PROJECT, 2023
** day0X - my_strupcase
** File description:
** Func to check if str is alpha
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int res = 1;

    if (str[0] == '\0')
        return res;
    for (int i = 0; str[i] != '\0' && res == 1; i++) {
        if (str[i] < 32 || (str[i] > 58 && str[i] < 64) || str[i] == 47)
            res --;
            }
    return res;
}
