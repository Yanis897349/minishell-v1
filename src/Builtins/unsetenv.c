/*
** EPITECH PROJECT, 2024
** minishell-v1
** File description:
** unsetenv
*/

#include "include/my_std.h"
#include "src/command.h"
#include "include/my_io.h"
#include "include/my_strings.h"
#include "src/env.h"
#include "src/shell.h"
#include <stdio.h>

static void unset(command_t *command, shell_t *shell)
{
    char **new_env = malloc(sizeof(char *) * (shell->env_size));
    char *to_find = malloc(sizeof(char) * (my_strlen(command->args[1]) + 1));
    int j = 0;

    if (new_env == NULL || to_find == NULL)
        return;
    to_find = my_strcpy(to_find, command->args[1]);
    to_find = my_strcat(to_find, "=");
    for (int i = 0; i < shell->env_size; i++) {
        if (my_strncmp(shell->env[i], to_find,
            my_strlen(to_find) - 1) == 0)
            continue;
        new_env[j] = my_strdup(shell->env[i]);
        j++;
    }
    free(to_find);
    my_freearray(shell->env);
    shell->env_size -= 1;
    new_env[shell->env_size] = NULL;
    shell->env = new_env;
}

void unset_env(command_t *command)
{
    shell_t *shell = get_shell(NULL);
    char *env = NULL;

    if (command->args_count == 0) {
        my_putstr("unsetenv: Too few arguments.\n");
        return;
    }
    env = my_getenv(command->args[1]);
    if (env == NULL)
        return;
    unset(command, shell);
}
