/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** shell
*/

#pragma once

typedef enum cmd_type_e {
    EXTERNAL = 0,
    BUILT_IN
} cmd_type_t;

typedef struct cmd_s {
    char *cmd;
    char **args;
    cmd_type_t type;
} cmd_t;

typedef struct shell_s {
    char **env;
} shell_t;

shell_t *init_shell(char **env);
