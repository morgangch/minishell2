/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** linked_list_utilities
*/

#include "my.h"

my_env_t *malloc_env(char *env)
{
    int j = 0;
    int k = 0;
    my_env_t *temp = malloc(sizeof(my_env_t));

    temp->name = malloc((my_strlen(env) + 1) * sizeof(char));
    temp->value = malloc((my_strlen(env) + 1) * sizeof(char));
    temp->next = NULL;
    for (; env[j] != '='; j++)
        temp->name[j] = env[j];
    temp->name[j] = '\0';
    j++;
    for (; env[j] != '\0'; j++) {
        temp->value[k] = env[j];
        k++;
    }
    temp->value[k] = '\0';
    return temp;
}

void my_env_init(char **envp, config_t *config)
{
    my_env_t *temp = NULL;

    config->env = malloc_env(envp[0]);
    for (int i = 1; envp[i] != NULL; i++) {
        temp = malloc_env(envp[i]);
        config->env = add_node(config->env, temp);
    }
}

static void free_env(my_env_t *env)
{
    my_env_t *tmp = env;
    my_env_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        if (tmp->name != NULL)
            free(tmp->name);
        if (tmp->value != NULL)
            free(tmp->value);
        if (next == NULL)
            break;
        free(tmp);
        tmp = next;
    }
    free(tmp);
    free(next);
}

static void free_cmd(cmd_t *cmd)
{
    cmd_t *tmp = cmd;
    cmd_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        if (tmp->args != NULL)
            free(tmp->args);
        if (tmp != NULL)
            free(tmp);
        if (next == NULL)
            break;
        tmp = next;
    }
    free(next);
}

void end_program(int status, config_t *config)
{
    free_env(config->env);
    if (config->input != NULL)
        free(config->input);
    if (config->cmd != NULL)
        free_cmd(config->cmd);
    if (config != NULL)
        free(config);
    exit(status);
}
