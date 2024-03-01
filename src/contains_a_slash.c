/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** contains_a_slash
*/

#include "../includes/minishell.h"

int contains_a_slash(char *command_without_flag)
{
    for (int i = 0; command_without_flag[i] != '\0'; i++) {
        if (command_without_flag[i] == '/')
            return (1);
        if (command_without_flag[i] == ' ')
            return (0);
    }
    return (0);
}