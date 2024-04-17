/*
** EPITECH PROJECT, 2023
** day04 - my_strlen
** File description:
** Func to display the count of characters of a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        cpt++;
    }
    return cpt;
}

int is_rejected(char c, char *reject)
{
    for (int j = 0; reject[j] != '\0'; j++) {
        if (c == reject[j]) {
            return 1;
        }
    }
    return 0;
}

int my_strcspn(char const *str, char *reject)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_rejected(str[i], reject)) {
            return cpt;
        }
        cpt++;
    }
    return cpt;
}
