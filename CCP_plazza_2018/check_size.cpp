/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** check size
*/

#include "my.hpp"

int still_check_size(std::string buf)
{
    if (strcmp(buf.c_str(), "S") == 0)
        return (S);
    else if (strcmp(buf.c_str(), "M") == 0)
        return (M);
    else if (strcmp(buf.c_str(), "L") == 0)
        return (L);
    else if (strcmp(buf.c_str(), "XL") == 0)
        return (XL);
    else if (strcmp(buf.c_str(), "XXL") == 0)
        return (XXL);
    return (84);
}

int check_size(ini::Info info, std::vector<std::string> size)
{
    int i = 0;

    while (i != info.g_how()) {
        if (still_check_size(size.at(i)) == 84) {
            std::cerr << "Error: Size format is wrong\n";
            return (84);
        }
        i++;
    }
    if (check_nbr(info) == 84)
        return (84);
    return (0);
}
