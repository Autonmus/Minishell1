/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** is_alphanumeric
*/

#include "../includes/minishell.h"

int is_alphanumeric(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            continue;
        if (str[i] >= 'a' && str[i] <= 'z')
            continue;
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        return (0);
    }
    return (1);
}
