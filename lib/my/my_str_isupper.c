/*
** EPITECH PROJECT, 2023
** day0X - my_strupcase
** File description:
** Func to check if str is upcase
*/

#include "my.h"

int my_char_islower(char c)
{
    char *alpha = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; alpha[i] != '\0'; i++) {
        if (c == alpha[i]) {
            return 1;
        }
    }
    return 0;
}

int my_str_isupper(char const *str)
{
    int res = 1;
    int comp;

    if (str[0] == '\0')
        return res;
    for (int i = 0; str[i] != '\0' && res == 1; i++) {
        comp = my_char_islower(str[i]);
        if (comp == 1) {
            res = 0;
        }
    }
    return res;
}
