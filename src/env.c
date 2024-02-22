/*
** EPITECH PROJECT, 2024
** minishell-v1
** File description:
** env
*/

#include "shell.h"
#include "include/my_strings.h"
#include <stddef.h>
#include <stdio.h>

char *my_getenv(const char *name)
{
    shell_t *shell = get_shell(NULL);

    for (int i = 0; shell->env[i] != NULL; i++) {
        if (my_strncmp(shell->env[i], name, my_strlen(name) - 1) == 0) {
            return shell->env[i] + my_strlen(name);
        }
    }
    return NULL;
}
