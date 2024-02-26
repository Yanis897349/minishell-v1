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
        my_putstr("Floating exception");
    }
    if (WTERMSIG(child_status) == SIGSEGV) {
        handled = 1;
        my_putstr("Segmentation fault");
    }
    if (WCOREDUMP(child_status))
        my_putstr(" (core dumped)");
    if (handled)
        my_putstr("\n");
}
