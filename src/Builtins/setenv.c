/*
** EPITECH PROJECT, 2024
** minishell-v1
** File description:
** setenv
*/

#include "include/my_io.h"
#include "src/command.h"
#include "src/env.h"
#include "src/shell.h"
#include "include/my_ctype.h"
#include "include/my_strings.h"
#include <stdio.h>

static int check_args_sanity(char **args)
{
    if (!my_isalpha(args[1][0])) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (my_str_isalphanum(args[1]) == 0) {
        my_putstr("setenv: Variable name must");
        my_putstr(" contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

static void replace_env(command_t *command, shell_t *shell)
{
    char *name = command->args[1];
    char *value = command->args[2];
    char *path_name = malloc(my_strlen(name) + 2);

    my_strcpy(path_name, name);
    my_strcat(path_name, "=");
    for (int i = 0; shell->env[i] != NULL; i++) {
        if (my_strncmp(shell->env[i], path_name,
            my_strlen(path_name) - 1) == 0) {
            free(shell->env[i]);
            shell->env[i] = malloc(my_strlen(name) + my_strlen(value) + 2);
            my_strcpy(shell->env[i], name);
            my_strcat(shell->env[i], "=");
            my_strcat(shell->env[i], value);
            free(path_name);
            return;
        }
    }
    free(path_name);
}

static void build_new_env(char **env, char *name, char *value)
{
    my_strcpy(*env, name);
    my_strcat(*env, "=");
    my_strcat(*env, value);
}

static void create_env(command_t *command, shell_t *shell)
{
    char **env = malloc(sizeof(char *) * (shell->env_size + 2));
    char *name = command->args[1];
    char *value = NULL;

    my_memset(env, 0, sizeof(char *) * (shell->env_size + 2));
    if (env == NULL)
        return;
    if (command->args_count == 1)
        value = my_strdup("");
    else
        value = command->args[2];
    for (int i = 0; i < shell->env_size; i++) {
        env[i] = my_strdup(shell->env[i]);
        free(shell->env[i]);
    }
    free(shell->env);
    env[shell->env_size] = malloc(my_strlen(name) + my_strlen(value) + 2);
    build_new_env(&env[shell->env_size], name, value);
    shell->env = env;
    shell->env_size++;
}

void set_env(command_t *command)
{
    shell_t *shell = get_shell(NULL);
    char *env_var = NULL;

    if (command->args_count == 0) {
        show_env(command);
        return;
    }
    if (command->args_count > 2) {
        my_putstr("setenv: Too many arguments.\n");
        return;
    }
    if (check_args_sanity(command->args) == 1)
        return;
    env_var = my_getenv(command->args[1]);
    if (env_var != NULL)
        replace_env(command, shell);
    else
        create_env(command, shell);
}
