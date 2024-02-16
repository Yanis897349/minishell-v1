/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** external
*/

#pragma once
#include "command.h"

char **build_exec_paths(char *cmd, char **env);
char *find_execute_paths(char **paths);
void execute_external(command_t command);
