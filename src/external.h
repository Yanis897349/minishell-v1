/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** external
*/

#pragma once

char **build_exec_paths(char *cmd, char **env);
void try_execute_paths(char **paths, char **args, char **env);
