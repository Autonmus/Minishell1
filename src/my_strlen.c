/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** my_strlen
*/

#include "../includes/minishell.h"

int my_strlen(char *src)
{
    int i = 0;

    while (src[i] != '\0')
        i++;
    return (i + 1);
}
