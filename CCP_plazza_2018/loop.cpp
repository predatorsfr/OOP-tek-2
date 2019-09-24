/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** loop file
*/

#include "my.hpp"

void loop4(ini::Info *info, const int chiefs)
{
    int buf;

    buf = info->g_to_m() / chiefs;
    if (info->g_to_m() % chiefs != 0) {
        buf = buf + 1;
    }
    info->s_kitchen(buf);
}

void loop3(ini::Info *info, std::vector<int> n_nb)
{
    int i = 0;
    int j = 0;

    while (i != info->g_how()) {
        j = j + n_nb.at(i);
        i++;
    }
    info->s_num(n_nb);
    info->a_to_m(j);
}

int loop2(int i, std::string buf)
{
    int j = 0;

    if (i != 0)
        buf.erase(buf.length() - 1);
    buf.erase(0, 1);
    j = std::atoi(buf.c_str());
    return (j);
}

int loop(ini::Info *info, std::string tamp, ini::get_ready get_ready)
{
    std::vector<std::string> nbr;
    std::vector<int> n_nb;
    int i = 0;

    printf("OK\n");
    if (tamp == "exit")
        exit(0);
    info->init_info(tamp);
    nbr = info->g_nbr();
    while (i != info->g_how() - 1) {
        n_nb.push_back(loop2(0, nbr.at(i)));
        i++;
    }
    n_nb.push_back(loop2(1, nbr.at(info->g_how() - 1)));
    loop3(info, n_nb);
    fork(info, get_ready);
    return (0);
}
