/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** cd
*/

#include <unistd.h>
#include "src/command.h"

void change_directory(command_t *command)
{
    chdir(command->args[1]);
}
