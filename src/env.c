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
#include <stdlib.h>

char *my_getenv(const char *name)
{
    shell_t *shell = get_shell(NULL);
    char *path_name = malloc(my_strlen(name) + 2);

    my_memset(path_name, 0, my_strlen(name) + 2);
    my_strcpy(path_name, name);
    my_strcat(path_name, "=");
    for (int i = 0; shell->env[i] != NULL; i++) {
        if (my_strncmp(shell->env[i], path_name,
            my_strlen(path_name) - 1) == 0) {
            free(path_name);
            return shell->env[i] + my_strlen(name) + 1;
        }
    }
    free(path_name);
    return NULL;
}
