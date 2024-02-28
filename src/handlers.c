/*
** EPITECH PROJECT, 2024
** minishell-v1
** File description:
** signal
*/

#include "include/my_io.h"
#include <signal.h>
#include <sys/wait.h>

void handle_signal(int child_status)
{
    int handled = 0;

    if (WTERMSIG(child_status) == SIGFPE) {
        handled = 1;
        my_putstr_error("Floating exception");
    }
    if (WTERMSIG(child_status) == SIGSEGV) {
        handled = 1;
        my_putstr_error("Segmentation fault");
    }
    if (WCOREDUMP(child_status))
        my_putstr_error(" (core dumped)");
    if (handled)
        my_putstr_error("\n");
}
