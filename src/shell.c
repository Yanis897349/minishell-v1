/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** shell
*/

#include "shell.h"
#include "include/my_strings.h"
#include "src/env.h"
#include <stdio.h>
#include <stdlib.h>

shell_t *init_shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    int env_size = my_array_len(env);

    if (shell == NULL)
        return NULL;
    shell->env_size = env_size;
    shell->env = malloc(sizeof(char *) * (env_size + 1));
    if (shell->env == NULL) {
        free(shell);
        return NULL;
    }
    my_memset(shell->env, 0, sizeof(char *) * (env_size + 1));
    for (int i = 0; i < env_size; i++) {
        shell->env[i] = my_strdup(env[i]);
    }
    return shell;
}

shell_t *get_shell(char **env)
{
    static shell_t *shell = NULL;

    if (shell == NULL && env != NULL) {
        shell = init_shell(env);
        shell->old_pwd = my_strdup(my_getenv("OLDPWD="));
    }
    return shell;
}

void destroy_shell(shell_t *shell)
{
    for (int i = 0; i < shell->env_size; i++) {
        free(shell->env[i]);
    }
    free(shell->env);
    if (shell->old_pwd != NULL)
        free(shell->old_pwd);
    free(shell);
}
