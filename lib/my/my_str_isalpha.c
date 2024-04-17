/*
** EPITECH PROJECT, 2023
** day0X - my_strupcase
** File description:
** Func to check if str is alpha
*/

int my_char_isalpha(char c)
{
    char *alpha = "abcdefghijklmnopqrstuvwxyz";
    char *alpha2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; alpha[i] != '\0'; i++) {
        if (c == alpha[i] || c == alpha2[i])
            return 1;
    }
    return 0;
}

int my_str_isalpha(char const *str)
{
    int res = 1;
    int comp;

    if (str[0] == '\0')
        return res;
    for (int i = 0; str[i] != '\0' && res == 1; i++) {
        comp = my_char_isalpha(str[i]);
        if (comp == 0)
            res --;
    }
    return res;
}
