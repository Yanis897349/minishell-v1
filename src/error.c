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

void print_cmd_not_found(command_t *command)
{
    my_putstr_error(command->name);
    my_putstr_error(": Command not found.\n");
}

void print_not_directory(command_t *command)
{
    my_putstr_error(command->args[1]);
    my_putstr_error(": Not a directory.\n");
}

void print_not_enough_rights(command_t *command)
{
    if (command->args[1] == NULL)
        my_putstr_error(command->name);
    else
        my_putstr_error(command->args[1]);
    my_putstr_error(": Permission denied.\n");
}

void print_format_error(command_t *command)
{
    my_putstr_error(command->name);
    my_putstr_error(": Exec format error. Wrong Architecture.\n");
}

static void print_errno(command_t *command)
{
    my_putstr_error(command->name);
    my_putstr_error(": ");
    my_putstr_error(strerror(errno));
    my_putstr_error(".\n");
}

void handle_error(command_t *command, int status)
{
    shell_t *shell = get_shell(NULL);
    int handled = 0;

    for (int i = 0; ERROR_HANDLERS[i].error_code != 0; i++) {
        if (errno == ERROR_HANDLERS[i].error_code) {
            ERROR_HANDLERS[i].handler(command);
            handled = 1;
            break;
        }
    }
    if (!handled)
        print_errno(command);
    if (status != -1)
        return;
    destroy_command(*command);
    destroy_shell(shell);
    exit(EXIT_FAILURE);
}
