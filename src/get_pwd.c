/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** get_pwd
*/

#include "../includes/minishell.h"
#include <unistd.h>
#include <stdlib.h>

char *get_pwd(void)
{
    char *temp = malloc(sizeof(char) * 2);
    size_t size = 0;

    while (getcwd(temp, size) == NULL) {
        temp = malloc(sizeof(char) * size + 1);
        size++;
    }
    return temp;
}
