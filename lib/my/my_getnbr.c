/*
** EPITECH PROJECT, 2023
** day0X - my_strupcase
** File description:
** Func to check if str is alpha
*/

#include <limits.h>
#include "my.h"

void car_checker(char c, int *sign, int *sign2, int *mark)
{
    if (c == '-')
        (*sign)++;
    else if (c == '+')
        (*sign2)++;
    else
        (*mark)--;
}

int my_getnbr(char const *str)
{
    int res = 0;
    int sign = 0;
    int mark = 1;
    int sign2 = 0;

    for (int i = 0; str[i] != '\0'; i ++) {
        if (res >= INT_MAX - 1 || res <= INT_MIN + 1)
            return 0;
        if (str[i] >= 48 && str[i] <= 57 && mark > 0)
            res = res * 10 + str[i] - '0';
        else
            car_checker(str[i], &sign, &sign2, &mark);
    }
    if (sign % 2 != 0 && sign - sign2 > 0)
        res = res * -1;
    if (res >= INT_MAX - 1 || res <= INT_MIN + 1
        || res == -1794967296 || res == 1794967296)
        res = 0;
    return res;
}
