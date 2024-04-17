/*
** EPITECH PROJECT, 2023
** myprintf - main file
** File description:
** Main
*/

#include "my.h"

int char_checker2(va_list ap, char c)
{
    switch (c) {
    case 'c':
        my_putchar((char) va_arg(ap, int));
        return 0;
    case '%':
        my_putchar('%');
        return 0;
    default:
        return 1;
    }
}

int char_checker(va_list ap, char c)
{
    char *s;
    long int i = 0;

    switch (c) {
    case 's':
        s = va_arg(ap, char *);
        my_putstr(s);
        return 0;
    case 'i' :
    case 'd' :
        i = va_arg(ap, long int);
        my_put_nbr(i);
        return 0;
    default:
        return char_checker2(ap, c);
    }
}

void myprintf_part(char *s, int *i, int *cpt, va_list ap)
{
    if (s[*i] == '%' && s[*i + 1] != '\0' && s[*i + 1] != '.') {
        (*i)++;
        *cpt += char_checker(ap, s[*i]);
    } else if (s[*i] == '%' && s[*i + 1] != '\0' && s[*i + 1] == '.') {
        *i += 2;
    } else {
        my_putchar(s[*i]);
        *cpt += 1;
    }
    (void) *cpt;
}

int my_printf(char *s, ...)
{
    va_list ap;
    int cpt = 0;

    va_start(ap, s);
    if (*s == '\0')
        return my_error_handler(1);
    for (int i = 0; s[i] != '\0'; i++)
        myprintf_part(s, &i, &cpt, ap);
    va_end(ap);
    return cpt;
}
