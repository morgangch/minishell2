/*
** EPITECH PROJECT, 2023
** day05 - my_find_prime_sup
** File description:
** Func that returns the lowest prime bigger than the int
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int test = 0;

    for (int i = nb; i < nb * 10; i ++) {
        test = my_is_prime(i);
        if (test == 1) {
            return i;
        }
    }
    return 0;
}
