/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** piping
*/

#include "my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void split_commands(char *input, cmd_t *cmd)
{
    cmd_t *cmd_buff = cmd;
    char *token = strtok(input, "|><");

    while (token != NULL) {
        printf("%s\n", token);
        cmd_buff->full_command = token;
        get_args(token, cmd_buff);
        token = strtok(NULL, "|><");
        cmd->next = malloc(sizeof(cmd_t));
        cmd_buff = cmd->next;
    }
}

int pipe_handling(config_t *config, cmd_t *cmd)
{
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1)
        exit(EXIT_FAILURE);
    pid = fork();
    if (pid == -1)
        exit(1);
    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        execve(cmd->name, cmd->args, config->envp);
        perror("execve ls");
    } else {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        execve(cmd->next->name, cmd->next->args, config->envp);
    }
    return 0;
}

int main(void)
{
    char *input = malloc(sizeof(char) * 100);
    strcpy(input, "/bin/ls -l | /usr/bin/grep src");
    cmd_t *cmd = malloc(sizeof(cmd_t));
    config_t *config = malloc(sizeof(config_t));

    cmd->args = malloc(sizeof(char *) * 100);
    config->cmd = cmd;
    config->envp = NULL;
    cmd->next = malloc(sizeof(cmd_t));
    split_commands(input, cmd);
    for (int i = 0; cmd->args[i] != NULL; i++)
        printf("%s\n", cmd->args[i]);
    printf("| %s", cmd->next->name);
    for (int i = 0; cmd->next->args[i] != NULL; i++)
        printf("%s\n", cmd->next->args[i]);
    pipe_handling(config, cmd);
    return 0;
}