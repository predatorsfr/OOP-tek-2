/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** check nbr
*/

#include "my.hpp"

int still_check_type(std::string buf)
{
    int i = buf.length() - 1;
    int j = 0;
    
    if (buf.at(0) != 'x' || i == 0)
        return (84);
    if (buf.at(1) == '0')
        return (84);
    while (j != i) {
        if (buf.at(j + 1) > '9' || buf.at(j + 1) < '0') {
            std::cerr << "quantity should have the following format:";
            std::cerr << "x[number greater than 0] and not " << buf.at(j + 1) << "\n";
            return (84);
        }
        j++;
    }
    return (0);
}

int check_type(std::string buf, int i)
{
    int j = buf.length() - 2;
    int k = 0;
    
    if (i == 1)
        return still_check_type(buf);
    if (buf.at(0) != 'x' || j == 0)
        return (84);
    while (k != j) {
        if (buf.at(j + 1) != ';') {
            std::cerr << "Error: Separator should be ';' ";
            std::cerr << "but it is : " << buf.at(j + 1) << "\n";
            return (84);
        }
        if (buf.at(k + 1) > '9' || buf.at(k + 1) < '0') {
            std::cerr << "Error: Quantity should have the following format:x[number";
            std::cerr << " greater than 0] and not " << buf.at(i + 1) << "\n";
            return (84);
        }
        i++;
    }
    return (0);
}

int check_nbr(ini::Info info)
{
    std::vector<std::string> nbr = info.g_nbr();
    int i = 0;

    while ((i + 1) != info.g_how()) {
        if (check_type(nbr.at(i), 0) == 84)
            return (84);
        i++;
    }
    if (check_type(nbr.at(info.g_how() - 1), 1) == 84)
        return (84);
    return (0);
}
