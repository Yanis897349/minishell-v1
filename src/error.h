/*
** EPITECH PROJECT, 2024
** minishell-v1
** File description:
** error
*/

#pragma once

#include "src/command.h"
#include <errno.h>
#include <stddef.h>

typedef struct error_handler_s {
    int error_code;
    void (*handler)(command_t *command);
} error_handler_t;

void print_cmd_not_found(command_t *command);
void print_not_enough_rights(command_t *command);

static const error_handler_t ERROR_HANDLERS[] = {
    {ENOENT, &print_cmd_not_found},
    {EACCES, &print_not_enough_rights},
    {0, NULL}
};

void handle_error(command_t *command, int status);
