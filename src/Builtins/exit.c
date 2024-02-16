/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** exit
*/

#include "include/my_io.h"
#include "src/command.h"

void exit_shell(command_t *command)
{
    my_putstr("exit\n");
    exit(0);
}
