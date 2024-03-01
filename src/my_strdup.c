/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "../includes/minishell.h"

char *my_strdup(char *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (int i = 0; i < my_strlen(src); i++) {
        str[i] = src[i];
    }
    return str;
}
