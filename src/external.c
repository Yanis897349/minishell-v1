/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** external
*/

#include "include/my_strings.h"
#include "include/my_std.h"
#include "command.h"
#include "error.h"
#include "env.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

static char **get_paths(char **env)
{
    char **path = NULL;
    char *tmp = NULL;
    int i = 0;

    tmp = my_strdup(my_getenv("PATH="));
    if (tmp == NULL)
        return NULL;
    path = buffer_to_array(tmp, ':');
    free(tmp);
    return path;
}

char **build_exec_paths(char *cmd, char **env)
{
    char **path = NULL;
    char *old_path = NULL;

    if (cmd == NULL)
        return NULL;
    path = get_paths(env);
    if (path == NULL)
        return NULL;
    for (int i = 0; path[i] != NULL; i++) {
        old_path = path[i];
        path[i] = malloc(my_strlen(old_path) + my_strlen(cmd) + 2);
        my_strcpy(path[i], old_path);
        free(old_path);
    }
    for (int i = 0; path[i] != NULL; i++) {
        if (path[i][my_strlen(path[i]) - 1] != '/')
            path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], cmd);
    }
    return path;
}

char *find_execute_paths(char **paths)
{
    char *path = NULL;

    if (paths == NULL)
        return NULL;
    for (int i = 0; paths[i] != NULL; i++) {
        if (access(paths[i], X_OK) == 0) {
            path = my_strdup(paths[i]);
            my_freearray(paths);
            return path;
        }
    }
    my_freearray(paths);
    return NULL;
}

void execute_external(command_t *command)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == -1) {
        perror("fork");
        exit(84);
    }
    if (pid != 0)
        return;
    if (command->exec.path != NULL)
        status = execve(command->exec.path, command->args, command->env);
    else
        status = execve(command->name, command->args, command->env);
    if (status == -1)
        handle_error(CMD_NOT_FOUND, command, status);
}
