/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** main
*/

#include "includes/minishell.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{
    minishell_t shell;

    shell.env = create_linked_list(env);
    shell.cpy_env = create_linked_list(env);
    if (argc != 1)
        return (84);
    return launch_terminal(&shell);
}
