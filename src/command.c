/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** command
*/

#include "command.h"
#include "external.h"
#include "include/my_strings.h"
#include "include/my_std.h"
#include "src/shell.h"
#include <stdio.h>
#include <stdlib.h>

static int count_args(char **args)
{
    int i = 0;

    for (; args[i] != NULL; i++);
    return i - 1;
}

static command_t build_builtin(char *cmd, char **args, char **env,
    void (*func)(command_t *command))
{
    command_t command;

    command.type = BUILTIN;
    command.name = cmd;
    command.args = args;
    command.args_count = count_args(args);
    command.env = env;
    command.exec.func = func;
    return command;
}

static command_t build_external(char *cmd, char **args, char **env)
{
    command_t command;

    command.type = EXTERNAL;
    command.name = cmd;
    command.args = args;
    command.args_count = count_args(args);
    command.env = env;
    command.exec.path = find_execute_paths(build_exec_paths(cmd, env));
    return command;
}

void destroy_command(command_t command)
{
    switch (command.type) {
        case BUILTIN:
            my_freearray(command.args);
            break;
        case EXTERNAL:
            if (command.exec.path != NULL)
                free(command.exec.path);
            my_freearray(command.args);
            break;
    }
    free(command.name);
}

command_t build_command(char *cmd, char **args)
{
    char **env = get_shell(NULL)->env;

    for (int i = 0; BUILTINS[i].name != NULL; i++)
        if (my_strcmp(cmd, BUILTINS[i].name) == 0)
            return build_builtin(cmd, args, env, BUILTINS[i].func);
    return build_external(cmd, args, env);
}

void run_command(command_t command)
{
    switch (command.type) {
        case BUILTIN:
            command.exec.func(&command);
            break;
        case EXTERNAL:
            execute_external(&command);
            break;
    }
    destroy_command(command);
}
