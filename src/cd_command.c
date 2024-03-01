/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** cd_command
*/

#include "../includes/minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int cd_command(char *command, minishell_t *shell)
{
    char *path;
    int count = get_count(command);
    char *actual_pwd = get_pwd();

    if (count == 0 || my_strcmp(get_path(command), "") == 0) {
        go_home(&shell->cpy_env);
        my_strcpy(shell->old_pwd, actual_pwd);
        return (0);
    } else if (my_strcmp(get_path(command), "-") == 0) {
        go_back(shell->old_pwd);
        my_strcpy(shell->old_pwd, actual_pwd);
        return (0);
    } else {
        path = get_path(command);
        my_strcpy(shell->old_pwd, actual_pwd);
        return chdir_with_error_message(path);
    }
}

static int chdir_with_error_message(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1) {
        my_puterr(path);
        my_puterr(": No such file or directory.\n");
        return (1);
    }
    if (!S_ISDIR(sb.st_mode)) {
        my_puterr(path);
        my_puterr(": Not a directory.\n");
        return (1);
    }
    if (chdir(path) == -1) {
        return (1);
    }
    return (0);
}

void go_back(char *old_pwd)
{
    chdir(old_pwd);
    return;
}

void go_home(linked_list_env_t **env)
{
    linked_list_env_t *current = (*env);

    while (my_strcmp(current->name, "HOME") != 0)
        current = current->next;
    chdir(current->value);
}

int get_count(char *command)
{
    int count = 0;

    for (int i = 0; i < my_strlen(command); i++) {
        if (command[i] == ' ')
            count += 1;
    }
    return count;
}

char *get_path(char *command)
{
    int i = 0;
    int k = 0;
    int count = 0;
    char *temp_str;

    for (; command[i - 1] != ' '; i++);
    for (int j = i; command[j] != '\n'; j++)
        count += 1;
    temp_str = malloc(sizeof(char) * count);
    for (; command[i] != '\n'; i++) {
        temp_str[k] = command[i];
        k += 1;
    }
    return temp_str;
}
