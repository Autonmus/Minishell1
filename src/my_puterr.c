/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** my_puterr
*/

#include "../includes/minishell.h"
#include <unistd.h>

void my_puterr(char *str)
{
    write(2, str, my_strlen(str) - 1);
}
