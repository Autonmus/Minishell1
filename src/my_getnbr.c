/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-julien.paillard
** File description:
** my_getnbr
*/

#include "../includes/minishell.h"

int my_getnbr(char *str)
{
    int neg = 1;
    int result = 0;
    int i;
    int k;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-') {
            neg = neg * (-1);
        }
    }
    for (k = i; str[k] != '\0'; k++) {
        if (str[k] >= '0' && str[k] <= '9') {
            result = result * 10;
            result = result + str[k] - '0';
        } else {
            return (result * neg);
        }
    }
    return (result * neg);
}
