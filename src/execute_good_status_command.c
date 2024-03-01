/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** execute_good_status_command
*/

#include "../includes/minishell.h"
#include <sys/wait.h>

int execute_good_status_command(int status)
{
    if (status == 11) {
        my_puterr("Segmentation fault\n");
        return (139);
    }
    if (status == 139) {
        my_puterr("Segmentation fault (core dumped)\n");
        return (139);
    }
    if (status != 131)
        return WEXITSTATUS(status);
}
