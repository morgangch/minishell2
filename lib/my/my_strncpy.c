/*
** EPITECH PROJECT, 2023
** day06 - my_strncpy
** File description:
** To copy a str in another one
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i != n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
