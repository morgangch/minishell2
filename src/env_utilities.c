/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** env utilities
*/

#include "my.h"

void cpy_list_to_envp(my_env_t *env, char **envp)
{
    my_env_t *buff = env;
    int i = 0;

    for (; buff != NULL; buff = buff->next) {
        envp[i] = malloc(sizeof(char) * (my_strlen(buff->name) +
        my_strlen(buff->value) + 2));
        my_strcpy(envp[i], buff->name);
        envp[i] = my_strcat(envp[i], "=");
        envp[i] = my_strcat(envp[i], buff->value);
        envp[i][my_strlen(buff->name) + my_strlen(buff->value) + 1] = '\0';
        i++;
    }
    envp[i] = NULL;
}

char *get_value_from_env(my_env_t *head, char *name)
{
    my_env_t *buff = head;

    for (; buff != NULL; buff = buff->next) {
        if (buff->name != NULL && my_strcmp(buff->name, name) == 0)
            return buff->value;
    }
    return NULL;
}
