/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** my_strcpy
*/

#include "../includes/minishell.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        if (src[i] != ',')
            dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy_spe(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        if (src[i] != ',' && src[i] != '\n')
            dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
