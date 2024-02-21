/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** exit
*/

#include "include/my_io.h"
#include "src/command.h"
#include "src/shell.h"

void exit_shell(command_t *command)
{
    shell_t *shell = get_shell(NULL);

    destroy_shell(shell);
    my_putstr("exit\n");
    exit(0);
}
