/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** builtin_handler
*/

#include "my.h"

static int is_in_list(char c)
{
    char const *good = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";

    for (int j = 0; good[j] != '\0'; j++) {
        if (c == good[j]) {
            return 1;
        }
    }
    return 0;
}

int is_valid(char const *str)
{
    int validChar = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        validChar = is_in_list(str[i]);
        if (!validChar)
            return 0;
    }
    return 1;
}

int is_builtin(cmd_t *cmd, config_t *config)
{
    if (cmd->name == NULL)
        return 0;
    if (is_builtin2(cmd, config))
        return 1;
    if (my_strcmp(cmd->name, "cd") == 0) {
        cd_builtin(cmd->args, config);
        return 1;
    }
    if (my_strcmp(cmd->name, "setenv") == 0) {
        setenv_builtin(cmd->args, config);
        return 1;
    }
    return 0;
}

int is_builtin2(cmd_t *cmd, config_t *config)
{
    if (my_strcmp(cmd->name, "unsetenv") == 0) {
        unsetenv_builtin(cmd->args, config);
        return 1;
    }
    if (my_strcmp(cmd->name, "env") == 0) {
        env_builtin(config->env);
        return 1;
    }
    if (my_strcmp(cmd->name, "exit") == 0) {
        end_program(0, config);
        return 1;
    }
    return 0;
}
