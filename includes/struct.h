/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct linked_list_env_s {
    char *name;
    char *value;
    struct linked_list_env_s *next;
} linked_list_env_t;

typedef struct minishell_s {
    linked_list_env_t *env;
    linked_list_env_t *cpy_env;
    int command_return;
    char *old_pwd;
} minishell_t;

typedef struct function_s {
    char *name;
    int (*function)(char *, minishell_t *shell);
} function_t;

typedef struct table_of_functions_s {
    const function_t *function_table;
    int size;
} table_of_function_t;

#endif /* !STRUCT_H_ */
