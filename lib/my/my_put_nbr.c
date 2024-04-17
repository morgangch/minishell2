/*
** EPITECH PROJECT, 2023
** Day07
** File description:
** My put nbr
*/

#include <unistd.h>
#include "my.h"

long int put_my_nbr(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        put_my_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return nb;
}

long int my_put_nbr(long int nb)
{
    put_my_nbr(nb);
    return nb;
}
