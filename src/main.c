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
#include "include/my_std.h"
#include "src/command.h"
#include "src/shell.h"
#include "include/my_std.h"

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

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv,
    char **env)
{
    shell_t *shell = get_shell(env);
    char **arg = NULL;
    char *input = NULL;

    if (shell == NULL)
        return 84;
    while (1) {
        if (isatty(STDIN_FILENO))
            my_putstr("$> ");
        input = get_user_input();
        if (my_strlen(input) == 0) {
            free(input);
            continue;
        }
        arg = buffer_to_array(input, ' ');
        run_command(build_command(input, arg));
        wait(NULL);
    }
    return 0;
}
