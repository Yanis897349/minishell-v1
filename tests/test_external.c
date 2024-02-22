/*
** EPITECH PROJECT, 2024
** minishell-v1 [WSL: Ubuntu]
** File description:
** test_external
*/

#include <criterion/criterion.h>
#include "src/external.h"

Test(build_exec_path, basic, .disabled = 1)
{
    char *cmd = "ls";
    char *env[] = {"SHELL=/bin/bash","PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Ruby32-x64/bin:/mnt/c/Program Files/OpenSSH/:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/c/Program Files/dotnet/:/mnt/c/Program Files/nodejs/:/mnt/c/Program Files/Docker/Docker/resources/bin:/mnt/c/Users/Admin/scoop/shims:/mnt/c/Users/Admin/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/Admin/AppData/Local/Programs/oh-my-posh/bin:/mnt/c/Users/Admin/AppData/Local/Programs/Microsoft VS Code/bin:/mnt/c/Users/Admin/AppData/Roaming/npm:/mnt/c/Users/Admin/.dotnet/tools:/snap/bin", NULL};
    char *expected[] = {"/usr/local/sbin/ls", "/usr/local/bin/ls", "/usr/sbin/ls", "/usr/bin/ls", "/sbin/ls", "/bin/ls", "/usr/games/ls", "/usr/local/games/ls", "/usr/lib/wsl/lib/ls", "/mnt/c/Ruby32-x64/bin/ls", "/mnt/c/Program Files/OpenSSH/ls", "/mnt/c/Windows/system32/ls", "/mnt/c/Windows/ls", "/mnt/c/Windows/System32/Wbem/ls", "/mnt/c/Windows/System32/WindowsPowerShell/v1.0/ls", "/mnt/c/Windows/System32/OpenSSH/ls", "/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common/ls", "/mnt/c/Program Files/dotnet/ls", "/mnt/c/Program Files/nodejs/ls", "/mnt/c/Program Files/Docker/Docker/resources/bin/ls", "/mnt/c/Users/Admin/scoop/shims/ls", "/mnt/c/Users/Admin/AppData/Local/Microsoft/WindowsApps/ls", "/mnt/c/Users/Admin/AppData/Local/Programs/oh-my-posh/bin/ls", "/mnt/c/Users/Admin/AppData/Local/Programs/Microsoft VS Code/bin/ls", "/mnt/c/Users/Admin/AppData/Roaming/npm/ls", "/mnt/c/Users/Admin/.dotnet/tools/ls", "/snap/bin/ls", NULL};
    char **path = build_exec_paths(cmd, env);

    cr_assert_not_null(path);
    for (int i = 0; path[i] != NULL; i++) {
        cr_assert_str_eq(path[i], expected[i]);
    }
}

Test(build_exec_path, no_path, .disabled = 1)
{
    char *cmd = "ls";
    char *env[] = {"SHELL=/bin/bash", NULL};
    char **path = build_exec_paths(cmd, env);

    cr_assert_null(path);
}

Test(build_exec_path, no_cmd, .disabled = 1)
{
    char *cmd = NULL;
    char *env[] = {"PATH=/bin", NULL};
    char **path = build_exec_paths(cmd, env);

    cr_assert_null(path);
}
