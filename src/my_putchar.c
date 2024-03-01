/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** my_putchar
*/

#include "../includes/minishell.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
