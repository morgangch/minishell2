/*
** EPITECH PROJECT, 2023
** day04 - my_swap
** File description:
** Func to swap two ints.
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int d = *a;

    *a = *b;
    *b = d;
}
