/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** cd
*/

#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my_io.h"
#include "include/my_strings.h"
#include "src/command.h"
#include "src/env.h"
#include "src/error.h"
#include "src/shell.h"

static void change_previous_directory(command_t *command, shell_t *shell)
{
    char *old_pwd = shell->old_pwd;
    char pwd[PATH_MAX];

    if (getcwd(pwd, PATH_MAX) == NULL) {
        handle_error(command, 0);
        return;
    }
    if (old_pwd == NULL) {
        my_putstr(": No such file or directory.\n");
        return;
    }
    if (chdir(old_pwd) == -1) {
        handle_error(command, 0);
    } else {
        shell->old_pwd = my_strdup(pwd);
        free(old_pwd);
    }
}

static void change_home_directory(command_t *command, shell_t *shell)
{
    char *home = my_getenv("HOME=");
    char pwd[PATH_MAX];

    if (getcwd(pwd, PATH_MAX) == NULL) {
        handle_error(command, 0);
        return;
    }
    if (home == NULL) {
        my_putstr("cd: No home directory.\n");
        return;
    }
    if (chdir(home) == -1)
        handle_error(command, 0);
    else {
        free(shell->old_pwd);
        shell->old_pwd = my_strdup(pwd);
    }
}

static void change_regular_directory(command_t *command, shell_t *shell)
{
    char *old_pwd = shell->old_pwd;
    char new_pwd[PATH_MAX];

    if (getcwd(new_pwd, PATH_MAX) == NULL) {
        handle_error(command, 0);
        return;
    }
    if (chdir(command->args[1]) == -1) {
        handle_error(command, 0);
    } else {
        shell->old_pwd = my_strdup(new_pwd);
        free(old_pwd);
    }
}

void change_directory(command_t *command)
{
    shell_t *shell = get_shell(NULL);

    if (command->args_count >= 2) {
        my_putstr("cd: Too many arguments.\n");
        return;
    }
    if (command->args[1] == NULL || my_strcmp(command->args[1], "~") == 0) {
        change_home_directory(command, shell);
        return;
    }
    if (command->args[1][0] == '-') {
        change_previous_directory(command, shell);
        return;
    }
    change_regular_directory(command, shell);
}
