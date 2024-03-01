/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** get_count
*/

#include "../includes/minishell.h"

int get_count_command(char *comm, int i)
{
    int count = 0;

    for (; comm[i] != ' ' &&
    comm[i] != '\n' && comm[i] != '\0' && comm[i] != '\t'; i++)
        count += 1;
    return count;
}
