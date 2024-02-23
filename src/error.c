/*
** EPITECH PROJECT, 2024
** minishell-v1
** File description:
** error
*/

#include "src/error.h"
#include "include/my_io.h"
#include "src/command.h"
#include "src/shell.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void handle_error(command_t *command, int status)
{
    shell_t *shell = get_shell(NULL);

    my_putstr(command->name);
    my_putstr(": ");
    my_putstr(strerror(errno));
    my_putstr(".\n");
    if (status != -1)
        return;
    destroy_command(*command);
    destroy_shell(shell);
    exit(EXIT_FAILURE);
}
