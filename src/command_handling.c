/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** command_handling
*/

#include "my.h"

void display_prompt(void)
{
    my_printf("$> ");
}

static int try_paths(char *cmd, char *args[], char **envp, char *path)
{
    char *cmd_path = NULL;

    if (cmd == NULL || path == NULL)
        return 1;
    for (char *token = strtok(path, ":"); token != NULL;
        token = strtok(NULL, ":")) {
        cmd_path =
            malloc(sizeof(char) * (my_strlen(token) + my_strlen(cmd) + 2));
        my_strcpy(cmd_path, token);
        cmd_path = my_strcat(cmd_path, "/");
        cmd_path = my_strcat(cmd_path, cmd);
        if (access(cmd_path, X_OK) == 0 && execve(cmd_path, args, envp)) {
            free(cmd_path);
            return 0;
        }
        free(cmd_path);
    }
    return 1;
}

static char *get_path(my_env_t *env, char **envp)
{
    char *path = NULL;

    for (my_env_t *buff = env; buff != NULL; buff = buff->next) {
        if (my_strcmp(buff->name, "PATH") == 0) {
            path = malloc(sizeof(char) * (my_strlen(buff->value) + 1));
            my_strcpy(path, buff->value);
            break;
        }
    }
    if (path != NULL)
        return path;
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_strncmp(envp[i], "PATH=", 5) == 0) {
            path = malloc(sizeof(char) * (my_strlen(envp[i] + 5) + 1));
            my_strcpy(path, envp[i] + 5);
            break;
        }
    }
    return path;
}

int check_path(cmd_t *cmd, my_env_t *env, char **envp)
{
    char *path = get_path(env, envp);

    if (execve(cmd->name, cmd->args, envp) == 0) {
        free(path);
        return 0;
    }
    if (try_paths(cmd->name, cmd->args, envp, path) == 0) {
        free(path);
        return 0;
    }
    free(path);
    return 1;
}

void handle_dumps(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    if (status == 256) {
        my_put_err("Segmentation fault\n");
        return;
    }
    if (WIFSIGNALED(status)) {
        if (WCOREDUMP(status))
            my_put_err("Segmentation fault (core dumped)\n");
    }
}

int execute_command(cmd_t *cmd, config_t *config)
{
    pid_t pid = fork();

    if (pid == -1) {
        my_put_err("Fork failed.\n");
        return 1;
    }
    if (pid == 0) {
        if (check_path(cmd, config->env, config->envp) == 1) {
            return 1;
        }
    } else {
        handle_dumps(pid);
    }
    return 0;
}

static void init_cmd(cmd_t *cmd, char *input, char *token)
{
    cmd->name = token;
    cmd->args = malloc(sizeof(char *) * 64);
    cmd->args[0] = token;
    cmd->full_command = input;
}

void parse_command(config_t *config)
{
    char *input = my_strdup(config->input);
    char *token = strtok(input, " ");
    cmd_t *cmd = malloc(sizeof(cmd_t));
    cmd_t *temp = NULL;

    init_cmd(cmd, config->input, token);
    for (int i = 1; token != NULL; i++) {
        token = strtok(NULL, " ");
        cmd->args[i] = token;
    }
    cmd->args[my_strlen(config->input)] = NULL;
    cmd->next = NULL;
    if (config->cmd == NULL)
        config->cmd = cmd;
    else {
        temp = config->cmd;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = cmd;
    }
}
