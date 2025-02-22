/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** shell
*/

#pragma once

typedef struct shell_s {
    char **env;
    int env_size;
    char *old_pwd;
} shell_t;

shell_t *init_shell(char **env);
shell_t *get_shell(char **env);
void destroy_shell(shell_t *shell);
