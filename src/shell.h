/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** shell
*/

#pragma once

typedef struct shell_s {
    char **env;
} shell_t;

shell_t *init_shell(char **env);
