/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** main
*/

#include <signal.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "include/my_strings.h"
#include "include/my_io.h"
#include "command.h"
#include "shell.h"
#include "handlers.h"

static char *get_user_input(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return NULL;
    }
    line[my_strlen(line) - 1] = '\0';
    return line;
}

static void print_prompt(void)
{
    if (isatty(STDIN_FILENO))
        my_putstr("$> ");
}

static int manage_user_input(void)
{
    char *input = NULL;
    char **arg = NULL;

    input = get_user_input();
    if (input == NULL)
        return 1;
    if (my_strlen(input) == 0) {
        free(input);
        return 0;
    }
    arg = buffer_to_array(input, ' ');
    run_command(build_command(input, arg));
    return 0;
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv,
    char **env)
{
    shell_t *shell = get_shell(env);
    int child_status = 0;

    if (shell == NULL)
        return 84;
    while (1) {
        print_prompt();
        if (manage_user_input() == 1)
            break;
        wait(&child_status);
        if (WIFSIGNALED(child_status))
            handle_signal(child_status);
    }
    destroy_shell(shell);
    if (WIFEXITED(child_status))
        exit(WEXITSTATUS(child_status));
    exit(child_status);
}
