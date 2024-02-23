/*
** EPITECH PROJECT, 2024
** minishell-v1
** File description:
** showenv
*/

#include "include/my_io.h"
#include "src/command.h"
#include "src/shell.h"
#include <stdio.h>

void show_env(command_t *command)
{
    shell_t *shell = get_shell(NULL);

    if (command->args_count != 0) {
        my_putstr("env: Too many arguments.\n");
        return;
    }
    for (int i = 0; i < shell->env_size; i++) {
        my_putstr(shell->env[i]);
        my_putstr("\n");
    }
}
