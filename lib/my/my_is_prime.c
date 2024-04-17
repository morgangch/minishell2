/*
** EPITECH PROJECT, 2023
** day05 - my_is_prime
** File description:
** Func that returns if the int is prime
*/

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int i = nb - 1; i > 1; i --) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
