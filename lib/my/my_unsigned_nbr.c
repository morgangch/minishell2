/*
** EPITECH PROJECT, 2023
** Nbr unsigned
** File description:
** Nbr unsigned for print
*/

#include "my.h"

int unsigned_my_nbr(unsigned long int nb)
{
    if (nb >= 10) {
        unsigned_my_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return nb;
}

int my_unsigned_nbr(unsigned long int nb)
{
    nb = unsigned_my_nbr(nb);
    return nb;
}
