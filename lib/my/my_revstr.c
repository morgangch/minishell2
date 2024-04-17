/*
** EPITECH PROJECT, 2023
** day06 - my_revstr
** File description:
** Func to reverse a str
*/

#include "my.h"

char *my_revstr(char *str)
{
    int str_len = my_strlen(str) - 1;
    char tempo;

    for (int i = 0; i <= str_len / 2; i++) {
        tempo = str[i];
        str[i] = str[str_len - i];
        str[str_len - i] = tempo;
    }
    return str;
}
