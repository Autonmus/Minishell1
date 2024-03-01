/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** execute_good_status_binarie_command
*/

#include "../includes/minishell.h"

int execute_good_status_binarie_command(int status, char *command)
{
    if (status == 256) {
        my_puterr(command);
        my_puterr(": Exec format error. Wrong Architecture.\n");
        return (1);
    }
    if (status == 11) {
        my_puterr("Segmentation fault\n");
        return (139);
    }
    if (status == 139) {
        my_puterr("Segmentation fault (core dumped)\n");
        return (139);
    }
}
