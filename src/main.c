/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** main
*/

#include <string.h>
#include "my.h"

int main(int ac, char **argc, char **envp)
{
    config_t *config = malloc(sizeof(config_t));

    my_env_init(envp, config);
    config->envp = envp;
    config->input = NULL;
    config->cmd = NULL;
    (void) ac;
    (void) argc;
    return minishell1(config);
}

static void minishell_loop_part(config_t *config)
{
    cmd_t *cmd = config->cmd;

    for (; cmd->next != NULL; cmd = cmd->next)
        ;
    if (!is_builtin(cmd, config) && execute_command(cmd, config) == 1) {
        my_printf("%s: Command not found.\n", cmd->name);
        return end_program(0, config);
    }
}

int minishell_loop(config_t *config)
{
    size_t input_size = 0;
    ssize_t read_result = 0;

    while (1) {
        if (isatty(0) == 1)
            display_prompt();
        read_result = getline(&config->input, &input_size, stdin);
        if (read_result == -1)
            end_program(0, config);
        if (read_result == 0 || my_strcmp(config->input, "exit") == 0)
            end_program(0, config);
        config->input[my_strcspn(config->input, "\n")] = '\0';
        parse_command(config);
        minishell_loop_part(config);
    }
    return 0;
}

int minishell1(config_t *config)
{
    int error = minishell_loop(config);

    end_program(error, config);
    return 0;
}
