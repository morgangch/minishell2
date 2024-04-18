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
    if (argv[0] != '\0')
        new = my_strcat(new, argv);
    new[my_strlen(str) + my_strlen(argv)] = '\0';
    return new;
}

int handle_error(char *home, char *old, char c)
{
    if (c == '~' && home == NULL) {
        my_put_err("cd: No home directory.\n");
        return 1;
    }
    if (c == '-' && old == NULL) {
        my_put_err("cd: No previous directory.\n");
        return 1;
    }
    return 0;
}

static char *handle_exception(char *argv, config_t *config)
{
    char *new = NULL;
    char *home = NULL;
    char *old = NULL;

    if (get_value_from_env(config->env, "OLDPWD") != NULL)
        old = my_strdup(get_value_from_env(config->env, "OLDPWD"));
    if (get_value_from_env(config->env, "HOME") != NULL)
        home = my_strdup(get_value_from_env(config->env, "HOME"));
    if (handle_error(home, old, argv[0]) == 1)
        return new;
    if (argv[0] == '~')
        new = realloc_str(home, argv + 1);
    else if (argv[0] == '-')
        new = realloc_str(old, argv + 1);
    else
        new = my_strdup(argv);
    return new;
}

void cd_builtin(char **args, config_t *config)
{
    char *new = NULL;
    char *old = my_strdup(get_value_from_env(config->env, "PWD"));

    if (args[1] == NULL) {
        if (get_value_from_env(config->env, "HOME") == NULL)
            return my_put_err("cd: No home directory.\n");
        new = my_strdup(get_value_from_env(config->env, "HOME"));
    } else
        new = handle_exception(args[1], config);
    if (new == NULL)
        return;
    if (chdir(new) == -1) {
        perror("cd");
        free(new);
        return;
    }
    setenv_builtin((char *[]){"setenv", "OLDPWD", old, NULL}, config);
    setenv_builtin((char *[]){"setenv", "PWD", new, NULL}, config);
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
