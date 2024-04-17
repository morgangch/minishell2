/*
** EPITECH PROJECT, 2024
** sokoban
** File description:
** str_to_word_array
*/

#include "my.h"

void skip(char **p)
{
    while (**p != '\0' && **p != ' ') {
        (*p)++;
    }
}

void str_to_word_array(char *str, char **arr)
{
    int index = 0;
    char *p = my_strdup(str);

    while (*p != '\0') {
        if (*p == ' ') {
            *p = '\0';
            p++;
        } else {
            arr[index] = p;
            index++;
            skip(&p);
        }
    }
    arr[index] = NULL;
}
