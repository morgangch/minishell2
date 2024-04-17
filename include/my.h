/*
** EPITECH PROJECT, 2023
** Lib header
** File description:
** header for lib
*/

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>

#define MIN_VAL(a, b, c) (a < b ? (a < c ? a : c) : (b < c ? b : c))

static const char *const error_codes[] = {"None",
    "Wrong parameter", "Unknown error"};

typedef struct my_env {
    char *name;
    char *value;
    struct my_env *next;
} my_env_t;

typedef struct cmd {
    char *name;
    char *full_command;
    int is_redir1;
    int is_redir2;
    int is_pipe;
    struct cmd *next;
    struct cmd *pipe;
    struct cmd *redir;
    char **args;
} cmd_t;

typedef struct config {
    my_env_t *env;
    char *input;
    cmd_t *cmd;
    char **envp;
    char *old_path;
} config_t;

int my_putchar(char);
long int my_put_nbr(long int);
int my_putstr(char const *);
int my_put_err(char const *);
int my_strcmp(char const *s1, char const *s2);
int my_error_handler(int code);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
int my_unsigned_nbr(unsigned long int nb);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_is_prime(int);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isupper(char const *str);
int my_str_islower(char const *str);
int my_char_isupper(char c);
int my_char_islower(char c);
char my_charupcase(char);
char my_charlowcase(char);
int my_str_isnum(char const *);
int my_str_isalpha(char const *);
int my_char_isalpha(char c);
int my_char_isnum(char c);
int my_getnbr(char const *str);
int my_printf(char *s, ...);
int my_len_nbr(int nb);
char *my_strdup(const char *src);
void str_to_word_array(char *str, char **arr);

/// @brief  Function to display something on the standard output
/// @param  s  The string to display
/// @param  ...  The arguments to replace in the string
/// @return
int my_printf(char *s, ...);
char *get_value_from_env(my_env_t *head, char *name);
void display_prompt(void);
int check_path(cmd_t *cmd, my_env_t *env, char **envp);
void parse_command(config_t *config);
int is_builtin(cmd_t *cmd, config_t *config);
int is_builtin2(cmd_t *cmd, config_t *config);
void cd_builtin(char **args, config_t *config);
void setenv_builtin(char **args, config_t *config);
void unsetenv_builtin(char **args, config_t *config);
void env_builtin(my_env_t *envp);
int minishell1(config_t *config);
int my_strcspn(char const *str, char *reject);
int get_list_len(my_env_t *head);
void display_list(my_env_t *list);
my_env_t *add_at_back(my_env_t *head, char *data, char *name);
void my_env_init(char **env, config_t *config);
void end_program(int status, config_t *config);
int execute_command(cmd_t *cmd, config_t *config);
my_env_t *node_del_by_value(my_env_t *head, char *value);
int is_valid(char const *str);
my_env_t *add_node(my_env_t *head, my_env_t *new_node);
void cpy_list_to_envp(my_env_t *env, char **envp);
