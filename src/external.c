/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** external
*/

#include "include/my_strings.h"
#include <stdio.h>
#include <stdlib.h>

static char **get_paths(char **env)
{
    char **path = NULL;
    char *tmp = NULL;
    int i = 0;

    for (; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 4) == 0) {
            tmp = my_strdup(env[i]);
            break;
        }
    }
    if (tmp == NULL)
        return NULL;
    tmp = my_strcpy(tmp, tmp + 5);
    path = buffer_to_array(tmp, ':');
    free(tmp);
    return path;
}

char **build_exec_paths(char **cmd, char **env)
{
    char **path = NULL;

    if (cmd == NULL || cmd[0] == NULL)
        return NULL;
    path = get_paths(env);
    if (path == NULL)
        return NULL;
    for (int i = 0; path[i] != NULL; i++) {
        if (path[i][my_strlen(path[i]) - 1] != '/')
            path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], cmd[0]);
    }
    return path;
}
