/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** len_tab
*/

#include "../includes/minishell.h"
#include <unistd.h>

int len_tab(char **args)
{
    int count = 0;

    for (int i = 0; args[i] != NULL; i++)
        count += 1;
    return count;
}
