/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** shell
*/

#include "shell.h"
#include <stdlib.h>

shell_t *init_shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));

    shell->env = env;
    return shell;
}
