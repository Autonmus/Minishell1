/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** my_strcat
*/

#include "../includes/minishell.h"
#include <stdlib.h>

char *my_strcat(char *str1, char *str2)
{
    int mutual_len = my_strlen(str1) + my_strlen(str2);
    char *dest = malloc(sizeof(char) * (mutual_len + 1));
    int j = 0;
    int i = 0;

    for (; i < my_strlen(str1); i++) {
        if (str1[i] == '\0')
            break;
        else
            dest[i] = str1[i];
    }
    for (; i < mutual_len; i++) {
        dest[i] = str2[j];
        j++;
    }
    return dest;
}
