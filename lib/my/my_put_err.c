/*
** EPITECH PROJECT, 2023
** u_funcs
** File description:
** functions
*/

#include <unistd.h>

int my_put_err(char const *str)
{
    for (int i = 0; str[i] != '\0'; i ++) {
        write(2, &str[i], 1);
    }
    return 84;
}
