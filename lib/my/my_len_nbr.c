/*
** EPITECH PROJECT, 2023
** nbrlen
** File description:
** my_len_nbr
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int my_len_nbr(int nb)
{
    int cpt = 0;

    while (nb > 9) {
        nb = nb / 10;
        cpt ++;
    }
    cpt ++;
    return cpt;
}
