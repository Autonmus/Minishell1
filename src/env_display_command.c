/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** env_display_command
*/

#include <unistd.h>
#include "../includes/minishell.h"

int env_display_command(char *command, minishell_t *shell)
{
    linked_list_env_t *current;

    current = shell->env;
    while (current != NULL && my_strcmp(current->name, "OLDPWD")) {
        my_putstr(current->name);
        my_putchar('=');
        my_putstr(current->value);
        my_putchar('\n');
        current = current->next;
    }
    return (0);
}
