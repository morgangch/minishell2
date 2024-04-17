/*
** EPITECH PROJECT, 2023
** dayX
** File description:
** my_putfloat
*/

#include "my.h"

float my_putfloat(float nb)
{
    int n = nb;
    int n2 = (nb - n) * 100;

    my_put_nbr(nb);
    my_putchar('.');
    my_put_nbr(n2);
    if (n == 0 && n2 == 0)
        my_putchar('0');
}
