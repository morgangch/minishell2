/*
** EPITECH PROJECT, 2023
** day03 - my_put_nbr
** File description:
** To display numbers as integers
*/

#include "my.h"

int op_counter(int nb, char const *base)
{
    int cpt;

    while (nb > 0) {
        nb /= my_strlen(base);
        cpt ++;
    }
    return cpt;
}

void my_put_nbr_base_r(int nb, char const *base, int x)
{
    for (int cpt = 0; nb != 0; cpt++) {
        if (cpt == x) {
            my_putchar(base[nb % my_strlen(base)]);
            return;
        }
        nb /= my_strlen(base);
    }
}

int my_put_nbr_base(int nb, char const *base)
{
    int op_nb;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    op_nb = op_counter(nb, base);
    for (int i = op_nb; i >= 0; i--)
        my_put_nbr_base_r(nb, base, i);
    return 0;
}
