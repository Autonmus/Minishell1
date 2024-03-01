/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** minishell
*/

#include "struct.h"

#ifndef MINISHELL_H_
    #define MINISHELL_H_

int find_good_command(char *command, minishell_t *shell);
int launch_terminal(minishell_t *shell);
void my_putchar(char c);
void my_putstr(char *str);
int my_strcmp(char *str1, char *str2);
int my_strlen(char *src);
int cd_command(char *command, minishell_t *shell);
char *my_strcpy(char *dest, char const *src);
char *get_command(char *command);
int case_error_cd_command(char *command);
char *get_path(char *command);
int env_display_command(char *command, minishell_t *shell);
char *my_strcat(char *str1, char *str2);
int execute_the_command_from_bin
(char *command, char *command_without_flag, linked_list_env_t *env);
int good_command_with_bin
(char *command, linked_list_env_t *env, char *command_without_flag);
char **get_args(char *command);
char *my_strdup(char *src);
char *my_strcpy_spe(char *dest, char const *src);
int setenv_command(char *command, minishell_t *shell);
int unsetenv_command(char *command, minishell_t *shell);
static int execute_the_command_from_binarie
(char *command, linked_list_env_t *env);
int execute_the_command
(char *command, linked_list_env_t *env, char *command_without_flag);
char *get_name_env(char *arg);
int my_tabcpy(char **dest, char **src);
int add_in_env(char *name, char *value, linked_list_env_t **env);
int len_tab(char **args);
static int replace_in_env(char *name, char *value, linked_list_env_t **env);
int check_if_name_valid(char *name, linked_list_env_t **env);
void delete_good_args(char *name, linked_list_env_t **env);
static char **get_args_env(char *command);
linked_list_env_t *create_linked_list(char **env);
void insert_element_in_list(char *arg, linked_list_env_t **temp);
int len_env(linked_list_env_t *env);
char **get_env_char(linked_list_env_t *env);
int get_count(char *command);
void go_home(linked_list_env_t **env);
void go_back(char *old_pwd);
static int chdir_with_error_message(char *path);
int exit_command(char *command, minishell_t *shell);
int my_getnbr(char *str);
void update_value_and_name(char *name, char *value, char **args);
int new_element_with_no_value(char *name, linked_list_env_t **env);
static int check_errors(char **args, char *name, char *value);
int is_alphanumeric(char *str);
void update_current_prev
(linked_list_env_t **current, linked_list_env_t **prev);
char **get_paths(char *command);
char **set_path(linked_list_env_t *current);
void update_command_return(int temp_command_return, minishell_t *shell);
static char *set_name(char *name);
static char *set_value(char *value);
int execute_good_status_command(int status);
int execute_good_status_binarie_command(int status, char *command);
void check_if_args_exit_is_good(char *arg);
char *get_pwd(void);
void my_puterr(char *str);
int get_count_command(char *comm, int i);
int contains_a_slash(char *command_without_flag);

#endif /* !MINISHELL_H_ */
