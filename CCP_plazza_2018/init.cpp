/*
** EPITECH PROJECT, 2019
** init
** File description:
** plazza
*/

#include "my.hpp"

int check_exit(std::string buf)
{
    std::string buf2;
    std::stringstream buf3(buf);
    int i = 0;

    if (strcmp(buf.c_str(), "exit") == 0)
        exit(0);
    while (buf3 >> buf2)
        i++;
    if (i %3 != 0)
        return (84);
    if (check_name(buf) == 84)
        return (84);
    return (0);
}

int pre_loop(ini::get_ready init)
{
    std::string tamp;
    ini::Info info;

    info.s_chiefs(init.g_arg2());
    info.s_to_m(0);
    for (; std::getline(std::cin, tamp);) {
        if (check_exit(tamp) == 84) {
            std::cout << "KO\n";
            return (84);
        }
        else if (loop(&info, tamp, init) == 84)
            continue;
    }
    return (0);
}

int init_arg(std::string arg1, std::string arg2, std::string arg3)
{
    if (arg1[0] != '0') {
        ini::get_ready init(std::atoi(arg1.c_str()),
                            std::atoi(arg2.c_str()),
                            std::atoi(arg3.c_str()));
        if (pre_loop(init) == 84)
            return (84);
    } else {
        ini::get_ready init(std::atof(arg1.c_str()),
                            std::atof(arg2.c_str()),
                            std::atof(arg3.c_str()));
        if (pre_loop(init) == 84)
            return (84);
    }
    return (0);
}
