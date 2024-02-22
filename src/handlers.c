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
    if (WTERMSIG(child_status) == SIGFPE)
        my_putstr("Floating exception");
    if (WTERMSIG(child_status) == SIGSEGV)
        my_putstr("Segmentation fault");
    if (WCOREDUMP(child_status))
        my_putstr(" (core dumped)");
    my_putstr("\n");
}
