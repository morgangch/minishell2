/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** linked_list_utilities
*/

#include "my.h"

int get_list_len(my_env_t *head)
{
    my_env_t *buff = head;
    int i = 0;

    while (buff != NULL) {
        i++;
        buff = buff->next;
    }
    return i;
}

int replace_node(my_env_t *head, char *data, char *name)
{
    my_env_t *buff = head;

    for (; buff != NULL; buff = buff->next) {
        if (buff->name != NULL && my_strcmp(buff->name, name) == 0) {
            free(buff->value);
            buff->value = malloc(sizeof(char) * (my_strlen(data) + 1));
            my_strcpy(buff->value, data);
            return 1;
        }
    }
    return 0;
}

my_env_t *add_node(my_env_t *head, my_env_t *new_node)
{
    my_env_t *buff = head;

    if (new_node == NULL)
        return head;
    if (head == NULL)
        head = new_node;
    else {
        buff = head;
        while (buff->next != NULL)
            buff = buff->next;
        buff->next = new_node;
    }
    return head;
}

my_env_t *add_at_back(my_env_t *head, char *data, char *name)
{
    my_env_t *new_node = malloc(sizeof(my_env_t));

    if (replace_node(head, data, name) == 1 || new_node == NULL)
        return head;
    new_node->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    new_node->value = malloc(sizeof(char) * (my_strlen(data) + 1));
    my_strcpy(new_node->name, name);
    my_strcpy(new_node->value, data);
    new_node->next = NULL;
    return add_node(head, new_node);
}

my_env_t *node_del_by_value(my_env_t *head, char *value)
{
    my_env_t *buff = head;
    my_env_t *prev = NULL;

    while (buff != NULL && my_strcmp(buff->name, value) != 0) {
        if (buff->next != NULL) {
            prev = buff;
            buff = buff->next;
        } else
            break;
    }
    if (buff != NULL) {
        if (prev == NULL)
            head = buff->next;
        else
            prev->next = buff->next;
        free(buff->name);
        free(buff->value);
        free(buff);
    }
    return head;
}
