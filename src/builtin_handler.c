/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** builtin_handler
*/

#include "my.h"

static char *realloc_str(char *str, char *argv)
{
    char *new = malloc(sizeof(char) *
    (my_strlen(str) + my_strlen(argv) + 1));

    new = my_strcpy(new, str);
    new = my_strcat(new, argv);
    new[my_strlen(str) + my_strlen(argv)] = '\0';
    return new;
}

static char *handle_exception(char *argv, config_t *config)
{
    char *new = NULL;
    char *home = malloc(sizeof(char) *
    my_strlen(get_value_from_env(config->env, "HOME")) + 1);
    char *old = malloc(sizeof(char) *
    my_strlen(get_value_from_env(config->env, "OLDPWD")) + 1);

    home = my_strcpy(home, get_value_from_env(config->env, "HOME"));
    old = my_strcpy(old, get_value_from_env(config->env, "OLDPWD"));
    if (argv[0] == '~') {
        new = realloc_str(home, argv + 1);
    } else if (argv[0] == '-') {
        new = realloc_str(old, argv + 1);
    } else {
        new = malloc(sizeof(char) * my_strlen(argv) + 1);
        new = my_strcpy(new, argv);
    }
    return new;
}

void cd_builtin(char **args, config_t *config)
{
    char *new = NULL;
    char *old = malloc(sizeof(char) *
    my_strlen(get_value_from_env(config->env, "PWD")) + 1);

    old = my_strcpy(old, get_value_from_env(config->env, "PWD"));
    if (args[1] == NULL) {
        new = realloc_str(get_value_from_env(config->env, "HOME"), "");
    } else
        new = handle_exception(args[1], config);
    if (new == NULL)
        return;
    if (chdir(new) == -1) {
        perror("cd");
        free(new);
        return;
    }
    config->env = add_at_back(config->env, old, "OLDPWD");
    config->env = add_at_back(config->env, new, "PWD");
    cpy_list_to_envp(config->env, config->envp);
    free(new);
}

static my_env_t *setenv_builtin2(char **args, my_env_t *env)
{
    char *data = args[2];
    bool isFreeble = false;

    if (data == NULL) {
        data = malloc(sizeof(char) * 1);
        my_strcpy(data, "");
        data[0] = '\0';
        isFreeble = true;
    }
    env = add_at_back(env, data, args[1]);
    if (isFreeble == true)
        free(data);
    return env;
}

void setenv_builtin(char **args, config_t *config)
{
    if (args[1] != NULL && is_valid(args[1]) == 1) {
        config->env = setenv_builtin2(args, config->env);
        cpy_list_to_envp(config->env, config->envp);
    } else if (args[1] == NULL)
        env_builtin(config->env);
    else {
        my_put_err("setenv: ");
        my_put_err("Variable name must contain alphanumeric characters.\n");
    }
}

void unsetenv_builtin(char **args, config_t *config)
{
    if (args[1] != NULL) {
        config->env = node_del_by_value(config->env, args[1]);
        cpy_list_to_envp(config->env, config->envp);
    } else
        my_put_err("unsetenv: missing argument\n");
}

void env_builtin(my_env_t *env)
{
    my_env_t *tmp = env;

    while (tmp != NULL) {
        if (tmp->name != NULL)
            my_printf("%s=", tmp->name);
        if (tmp->value != NULL)
            my_printf("%s", tmp->value);
        my_printf("\n");
        tmp = tmp->next;
    }
}
