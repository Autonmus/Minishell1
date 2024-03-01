/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** my_strcmp
*/

#include "../includes/minishell.h"

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (1);
    for (int i = 0; i < my_strlen(str1); i++) {
        if (str1[i] < str2[i])
            return (1);
        if (str1[i] > str2[i])
            return (-1);
    }
    return (0);
}
