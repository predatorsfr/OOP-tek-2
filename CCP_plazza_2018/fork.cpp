/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** fork
*/

#include "my.hpp"

int fork(ini::Info *info, ini::get_ready get_ready)
{
    pid_t pid = fork();
    std::vector<std::string> n = info->g_name();
    std::vector<int> nbr = info->g_num();
    int size = n.size();
    int size2 = nbr.size();
    int id = 0;
    key_t k = ftok(".data", 55);
    
    if (pid != 0 && getppid() != 0) {
        if (!size || !get_ready.g_arg1() || !size2)
            return (84);
        usleep(get_ready.g_arg1() * 200000);
        printf("kitchen ended all pizza, making next...\n");
        if (!(id = msgget(k, 8080 | IPC_CREAT)))
            return (84);
    }
    return (0);
}
