/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** get_paths
*/

#include "../includes/minishell.h"
#include <string.h>
#include <stdlib.h>

char **get_paths(char *command)
{
    char *str = my_strdup(command);
    char *str2 = my_strdup(command);
    char *token = strtok(str, ":");
    int count = 0;
    int j = 0;
    char **args;

    while (token != NULL) {
        count += 1;
        token = strtok(NULL, ":");
    }
    args = malloc(sizeof(char *) * ((count) + 1));
    token = strtok(str2, ":");
    for (int i = 0; token != NULL; i++) {
        args[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
        my_strcpy_spe(args[i], token);
        token = strtok(NULL, ":");
    }
    args[count + 1] = NULL;
    return args;
}

char **set_path(linked_list_env_t *current)
{
    char **paths;

    if (current == NULL) {
        paths = malloc(sizeof(char *) * 2);
        paths[0] = malloc(sizeof(char) * 6);
        my_strcpy(paths[0], "/bin");
    } else
        paths = get_paths(current->value);
    return paths;
}
