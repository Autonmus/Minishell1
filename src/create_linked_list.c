/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** create_linked_list
*/

#include "../includes/minishell.h"
#include <stdlib.h>
#include <string.h>

linked_list_env_t *create_linked_list(char **env)
{
    linked_list_env_t *temp = malloc(sizeof(linked_list_env_t));

    temp = NULL;
    for (int i = len_tab(env) - 1; env[i] != NULL; i--)
        insert_element_in_list(env[i], &temp);
    return temp;
}

void insert_element_in_list(char *arg, linked_list_env_t **temp)
{
    linked_list_env_t *new_element = malloc(sizeof(linked_list_env_t));
    char **args = get_args_env(arg);

    if (args[1] == NULL) {
        args[1] = malloc(sizeof(char) * 3);
        my_strcpy(args[1], "");
    }
    new_element->name = malloc(sizeof(char) * (my_strlen(args[0]) + 1));
    new_element->value = malloc(sizeof(char) * (my_strlen(args[1]) + 1));
    my_strcpy(new_element->name, args[0]);
    my_strcpy(new_element->value, args[1]);
    new_element->next = *temp;
    *temp = new_element;
}

static char **get_args_env(char *command)
{
    char *str = my_strdup(command);
    char *str2 = my_strdup(command);
    char *token = strtok(str, " = ");
    int count = 0;
    char **args = malloc(sizeof(char *) * (3));

    token = strtok(str2, " = ");
    for (int i = 0; token != NULL; i++) {
        args[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
        my_strcpy_spe(args[i], token);
        token = strtok(NULL, "");
    }
    args[2] = NULL;
    return args;
}
