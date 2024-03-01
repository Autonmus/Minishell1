/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** exit_command
*/

#include "../includes/minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int exit_command(char *command, minishell_t *shell)
{
    char **args = get_args(command);

    if (len_tab(args) == 1) {
        exit(shell->command_return);
    } else if (len_tab(args) == 2) {
        check_if_args_exit_is_good(args[1]);
    } else {
        my_puterr("exit: Expression Syntax.\n");
        return (1);
    }
}

void check_if_args_exit_is_good(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] < '0' || arg[i] > '9') {
            my_puterr("exit: Expression Syntax.\n");
            return;
        }
    }
    exit(my_getnbr(arg));
}
