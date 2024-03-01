/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** unsetenv_command
*/

#include "../includes/minishell.h"
#include <stdlib.h>

int unsetenv_command(char *command, minishell_t *shell)
{
    char **args = get_args(command);

    if (shell->env == NULL)
        return (1);
    if (len_tab(args) == 1) {
        my_puterr("unsetenv: Too few arguments.\n");
        return (1);
    }
    for (int i = 1; i < len_tab(args); i++) {
        if (check_if_name_valid(args[i], &shell->env) == 1) {
            delete_good_args(args[i], &shell->env);
        }
    }
    return (0);
}

void delete_good_args(char *name, linked_list_env_t **env)
{
    linked_list_env_t *current = *env;
    linked_list_env_t *prev = NULL;
    linked_list_env_t *temp;

    if (my_strcmp(name, (*env)->name) == 0) {
        temp = (*env);
        free(temp);
        (*env) = (*env)->next;
        return;
    }
    prev = current;
    current = current->next;
    while (current != NULL) {
        if (my_strcmp(current->name, name) == 0) {
            prev->next = current->next;
            free(current);
            return;
        }
        update_current_prev(&current, &prev);
    }
}

void update_current_prev(linked_list_env_t **current, linked_list_env_t **prev)
{
    (*prev) = (*current);
    (*current) = (*current)->next;
}
