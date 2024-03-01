/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** launch_terminal
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/minishell.h"

int launch_terminal(minishell_t *shell)
{
    size_t size = 0;
    char *command = NULL;
    int temp_command_return = 0;

    while (1) {
        if (isatty(0) != 0)
            my_putstr("$> ");
        if (getline(&command, &size, stdin) == -1)
            return shell->command_return;
        else {
            temp_command_return = find_good_command(command, shell);
            update_command_return(temp_command_return, shell);
        }
    }
    return (0);
}

void update_command_return(int temp_command_return, minishell_t *shell)
{
    if (temp_command_return != 0)
        shell->command_return = temp_command_return;
}
