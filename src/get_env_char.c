/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** get_env_char
*/

#include "../includes/minishell.h"
#include <stdlib.h>

char **get_env_char(linked_list_env_t *env)
{
    int count = len_env(env);
    char **temp = malloc(sizeof(char *) * (count + 1));
    linked_list_env_t *current = env;
    int i = 0;

    while (current != NULL) {
        temp[i] = malloc(sizeof(char) *
        (my_strlen(current->name) + my_strlen(current->value) + 2));
        my_strcpy(temp[i], my_strcat
        (current->name, my_strcat("=", current->value)));
        i++;
        current = current->next;
    }
    return temp;
}

int len_env(linked_list_env_t *env)
{
    linked_list_env_t *current = env;
    int count = 0;

    while (current != NULL) {
        current = current->next;
        count += 1;
    }
    return count;
}
