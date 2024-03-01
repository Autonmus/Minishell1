/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** get_args
*/

#include <string.h>
#include <stdlib.h>
#include "../includes/minishell.h"

char **get_args(char *command)
{
    char *str = my_strdup(command);
    char *str2 = my_strdup(command);
    char *token = strtok(str, " \t\n");
    int count = 0;
    int j = 0;
    char **args;

    while (token != NULL) {
        count += 1;
        token = strtok(NULL, " \t\n");
    }
    args = malloc(sizeof(char *) * ((count) + 1));
    token = strtok(str2, " \t\n");
    for (int i = 0; token != NULL; i++) {
        args[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
        my_strcpy_spe(args[i], token);
        token = strtok(NULL, " \t\n");
    }
    args[count + 1] = NULL;
    return args;
}
