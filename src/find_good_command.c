/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** find_good_command
*/

#include "../includes/macros.h"
#include "../includes/minishell.h"
#include "../includes/struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>

const function_t table_of_functions[] = {
    {"cd", cd_command},
    {"env", env_display_command},
    {"unsetenv", unsetenv_command},
    {"setenv", setenv_command},
    {"exit", exit_command}
};

int find_good_command(char *command, minishell_t *shell)
{
    table_of_function_t table_functions;
    char *command_without_flag = get_command(command);

    if (my_strcmp(command_without_flag, "") == 0)
        return (0);
    table_functions.function_table = table_of_functions;
    table_functions.size = SIZE_TAB;
    for (int i = 0; i < SIZE_TAB; i++) {
        if (my_strcmp(table_functions.function_table[i].name,
        command_without_flag) == 0)
            return table_functions.function_table[i].function(command, shell);
    }
    return good_command_with_bin
    (command, shell->cpy_env, command_without_flag);
}

int good_command_with_bin
(char *command, linked_list_env_t *env, char *command_without_flag)
{
    linked_list_env_t *current = env;
    char **paths;
    char **args = get_args(command);
    pid_t pid = fork();
    int status;

    while (current != NULL && my_strcmp(current->name, "PATH") != 0)
        current = current->next;
    paths = set_path(current);
    if (pid == 0) {
        for (int i = 0; i < len_tab(paths); i++)
            execve(my_strcat(paths[i], my_strcat("/", command_without_flag)),
            args, get_env_char(env));
        kill(getpid(), SIGQUIT);
    } else {
        waitpid(pid, &status, 0);
        if (status != 131)
            return execute_good_status_command(status);
    }
    return execute_the_command(command, env, command_without_flag);
}

int execute_the_command
(char *command, linked_list_env_t *env, char *command_without_flag)
{
    struct stat sb;

    command[my_strlen(command) - 2] = '\0';
    if (stat(command, &sb) == 0 && (sb.st_mode & S_IXUSR ||
    S_ISDIR(sb.st_mode) || S_ISREG(sb.st_mode)) &&
    contains_a_slash(command) == 1)
        return execute_the_command_from_binarie(command, env);
    else {
        my_puterr(command_without_flag);
        my_puterr(": Command not found.\n");
        return (1);
    }
}

static int execute_the_command_from_binarie
(char *command, linked_list_env_t *env)
{
    int status;
    pid_t pid = fork();

    if (pid == 0) {
        execve(command, get_args(command), get_env_char(env));
        return (1);
    } else {
        waitpid(pid, &status, 0);
        status = execute_good_status_binarie_command(status, command);
        return status;
    }
}

char *get_command(char *comm)
{
    char *temp_str;
    int count = 0;
    int i = 0;
    int j = 0;
    int t = 0;

    if (my_strcmp(comm, "\n") == 0)
        return "";
    for (; comm[i] <= 'a' || comm[i] >= 'z'; i++);
    j = i;
    count = get_count_command(comm, i);
    temp_str = malloc(sizeof(char) * (count + 1));
    for (; comm[j] != '\n' && comm[j] != '\t' &&
    comm[j] != ' ' && comm[j] != '\0'; j++) {
        temp_str[t] = comm[j];
        t++;
    }
    return temp_str;
}
