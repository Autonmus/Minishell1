/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** my_tabcpy
*/

#include "../includes/minishell.h"
#include <stdlib.h>
#include <unistd.h>

int my_tabcpy(char **dest, char **src)
{
    int i = 0;

    while (src[i] != NULL) {
        dest[i] = malloc(sizeof(char) * my_strlen(src[i]));
        my_strcpy(dest[i], src[i]);
        i += 1;
    }
    return (i);
}
