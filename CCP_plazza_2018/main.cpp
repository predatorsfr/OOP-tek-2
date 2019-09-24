/*
** EPITECH PROJECT, 2019
** main
** File description:
** plazza
*/

#include "my.hpp"

bool is_number(std::string buf)
{
    for (int i = 0; buf[i] != '\0'; i++) {
        if (isalpha(buf[i]) != 0 && buf[i] != '.')
            return (0);
    }
    return (1);
}

int check_error(int ac, char **av)
{   
    if (ac != 4) {
        return (84);
    }
    if (is_number(av[1]) == 0)
        return (84);
    if (is_number(av[2]) == 0)
        return (84);
    if (is_number(av[3]) == 0)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    if (check_error(ac, av) == 84)
        return (84);
    init_arg(av[1], av[2], av[3]);
    return (0);
}
