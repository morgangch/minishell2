/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** builtin_handler
*/

#include "my.h"

/*static char *handle_exception(char *argv, config_t *config)
{
    char *new = NULL;
    char *home = get_value_from_env(config->env, "HOME");
    char *old = NULL;
    old = my_strcpy(old, get_value_from_env(config->env, "OLDPWD"));

    if (argv[0] == '~') {
        new = malloc(sizeof(char) * (my_strlen(home) + my_strlen(argv) + 1));
        new = my_strcpy(new, home);
        if (argv[1] != '\0') {
            new = my_strcat(new, argv + 1);
            new[my_strlen(home) + my_strlen(argv) + 1] = '\0';
        } else
            new[my_strlen(home) + 1] = '\0';
        return new;
    }
    if (argv[0] == '-' && argv[1] == '\0') {
        return old;
    }
    return argv;
}*/

void cd_builtin(char **args, config_t *config)
{
    if (args[1] == NULL)
        my_put_err("cd: missing argument\n");
    else {
        if (chdir(args[1]) == -1)
            perror("cd");
    }
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
    else
        my_put_err("setenv: Variable name must contain alphanumeric characters.\n");
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
