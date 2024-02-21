/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** shell
*/

#include "shell.h"
#include "include/my_std.h"
#include <stdio.h>
#include <stdlib.h>

shell_t *init_shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));

    shell->env = env;
    return shell;
}

shell_t *get_shell(char **env)
{
    static shell_t *shell = NULL;

    if (shell == NULL && env != NULL)
        shell = init_shell(env);
    return shell;
}

void destroy_shell(shell_t *shell)
{
    free(shell);
}
