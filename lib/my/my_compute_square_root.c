/*
** EPITECH PROJECT, 2023
** day05 - my_compute_square_root
** File description:
** Func to return the square root of an int
*/

int my_compute_square_root(int nb)
{
    int i = nb / 2;
    int res = 0;

    while (i * i != nb) {
        i --;
        if (i <= 0) {
            return res;
        }
    }
    if (i * i == nb) {
        res = i;
    }
    return res;
}
