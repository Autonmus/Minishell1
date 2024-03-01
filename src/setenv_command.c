/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** setenv_command
*/

#include "../includes/minishell.h"
#include <stdlib.h>

int setenv_command(char *command, minishell_t *shell)
{
    char **args = get_args(command);
    char *name;
    char *value;

    if (len_tab(args) == 1)
        return env_display_command(NULL, shell);
    if (len_tab(args) >= 2 && args[1] != NULL)
        name = set_name(args[1]);
    else
        return (1);
    if (len_tab(args) == 3 && args[2] != NULL)
        value = set_value(args[2]);
    else
        my_strcpy(value, "");
    if (check_errors(args, name, value) == 1)
        return (1);
    if (check_if_name_valid(name, &shell->env) == 1)
        return replace_in_env(name, value, &shell->env);
    return add_in_env(name, value, &shell->env);
}

static char *set_value(char *value)
{
    char *temp = malloc(sizeof(char) * (my_strlen(value) + 1));

    my_strcpy(temp, value);
    return temp;
}

static char *set_name(char *name)
{
    char *temp = malloc(sizeof(char) * (my_strlen(name) + 1));

    my_strcpy(temp, name);
    return name;
}

static int check_errors(char **args, char *name, char *value)
{
    if (len_tab(args) > 3) {
        my_puterr("setenv: Too many arguments.\n");
        return (1);
    }
    if (is_alphanumeric(name) == 0) {
        my_puterr("setenv: Variable name must contain ");
        my_puterr("alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

int add_in_env(char *name, char *value, linked_list_env_t **env)
{
    linked_list_env_t *new_element = malloc(sizeof(linked_list_env_t));
    linked_list_env_t *current;

    if (my_strcmp(name, "") == 0)
        return (0);
    if (my_strcmp(value, "") == 0)
        return new_element_with_no_value(name, env);
    new_element->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    new_element->value = malloc(sizeof(char) * (my_strlen(value) + 1));
    my_strcpy(new_element->name, name);
    my_strcpy(new_element->value, value);
    new_element->next = *env;
    current = *env;
    while (current->next != NULL)
        current = current->next;
    current->next = new_element;
    new_element->next = NULL;
    return (0);
}

int new_element_with_no_value(char *name, linked_list_env_t **env)
{
    linked_list_env_t *new_element = malloc(sizeof(linked_list_env_t));
    linked_list_env_t *current;

    new_element->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    new_element->value = malloc(sizeof(char) * (2));
    my_strcpy(new_element->name, name);
    my_strcpy(new_element->value, "");
    new_element->next = *env;
    current = *env;
    while (current->next != NULL)
        current = current->next;
    current->next = new_element;
    new_element->next = NULL;
    return (0);
}

static int replace_in_env(char *name, char *value, linked_list_env_t **env)
{
    linked_list_env_t *current = *env;

    while (current != NULL) {
        if (my_strcmp(current->name, name) == 0) {
            my_strcpy(current->value, value);
            return (0);
        }
        current = current->next;
    }
    return (0);
}

int check_if_name_valid(char *name, linked_list_env_t **env)
{
    linked_list_env_t *current = *env;

    if (my_strcmp(name, "") == 0)
        return (0);
    for (int i = 0; current != NULL; current = current->next) {
        if (my_strcmp(current->name, name) == 0) {
            return (1);
        }
    }
}

char *get_name_env(char *arg)
{
    char *str = malloc(sizeof(char) * (my_strlen(arg)));

    for (int i = 0; arg[i] != '='; i++)
        str[i] = arg[i];
    return str;
}
