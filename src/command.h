/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** command
*/

#pragma once
#include <stddef.h>
#include <stdlib.h>

typedef enum command_type_e {
    EXTERNAL = 0,
    BUILTIN
} command_type_t;

typedef union command_exec_u {
    void (*func)();
    char *path;
} command_exec_t;

typedef struct command_s {
    command_type_t type;
    char *name;
    char **args;
    char **env;
    command_exec_t exec;
} command_t;

typedef struct builtins {
    char *name;
    void (*func)(command_t *command);
} builtins_t;

void exit_shell(command_t *command);
void change_directory(command_t *command);

static const builtins_t BUILTINS[] = {
    {"exit", &exit_shell},
    {"cd", &change_directory},
    {NULL, NULL}
};

void destroy_command(command_t command);
command_t build_command(char *cmd, char **args);
void run_command(command_t command);
