/*
** EPITECH PROJECT, 2023
** day05 - my_compute_power_rec
** File description:
** Func to return an int raised to power p
*/

#include <limits.h>

int my_compute_power_rec(int x, int n)
{
    if (x >= INT_MAX || x <= INT_MIN || n >= INT_MAX || n <= INT_MIN) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    return x * my_compute_power_rec(x, n - 1);
}
