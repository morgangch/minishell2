/*
** EPITECH PROJECT, 2023
** error_handler
** File description:
** tool to handle the error codes
*/

#include "my.h"

int my_error_handler(int code)
{
    my_put_err(error_codes[code]);
    return 84;
}
