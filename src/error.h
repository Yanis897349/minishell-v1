/*
** EPITECH PROJECT, 2024
** minishell-v1
** File description:
** error
*/

#pragma once

#include "src/command.h"
#include <stddef.h>

typedef enum error_e {
    CMD_NOT_FOUND = 1,
} error_t;

typedef struct error_handler_s {
    error_t error_code;
    void (*handler)(command_t *command, int status);
} error_handler_t;

void print_cmd_not_found(command_t *command, int status);

static const error_handler_t ERROR_HANDLERS[] = {
    {CMD_NOT_FOUND, &print_cmd_not_found},
    {0, NULL}
};

void handle_error(error_t error_code, command_t *command, int status);
