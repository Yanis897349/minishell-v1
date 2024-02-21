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
#include <stdio.h>
#include <stdlib.h>

void print_cmd_not_found(command_t *command, int status)
{
    my_putstr(command->name);
    my_putstr(": Command not found.\n");
}

void handle_error(error_t error_code, command_t *command, int status)
{
    shell_t *shell = get_shell(NULL);

    for (int i = 0; ERROR_HANDLERS[i].error_code != 0; i++) {
        if (error_code == ERROR_HANDLERS[i].error_code) {
            ERROR_HANDLERS[i].handler(command, status);
            break;
        }
    }
    destroy_command(*command);
    destroy_shell(shell);
    exit(status);
}
