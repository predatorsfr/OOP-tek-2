/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** check name
*/

#include "my.hpp"

int still_check_name(std::string buf)
{
    std::transform(buf.begin(), buf.end(), buf.begin(), tolower);
    if (strcmp(buf.c_str(), "americana") == 0)
        return (Americana);
    else if (strcmp(buf.c_str(), "fantasia") == 0)
        return (Fantasia);
    else if (strcmp(buf.c_str(), "margarita") == 0)
        return (Margarita);
    else if (strcmp(buf.c_str(), "regina") == 0)
        return (Regina);
    return (0);
}

int check_name(std::string buf)
{
    ini::Info info;
    std::vector<std::string> name;
    std::vector<std::string> size;
    int	i = 0;

    info.init_info(buf);
    name = info.g_name();
    size = info.g_size();
    while (i != info.g_how()) {
        if (still_check_name(name.at(i)) == 0) {
            std::cerr << "Error: Pizza Name is wrong\n";
            return (84);
        }
        i++;
    }
    if (check_size(info, size) == 84)
        return (84);
    return (0);
}
