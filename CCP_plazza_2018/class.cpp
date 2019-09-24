/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** get_ready class
*/

#include "my.hpp"

ini::get_ready::get_ready(float arg1, int arg2, int arg3): _arg1(arg1), _arg2(arg2), _arg3(arg3)
{

}

ini::get_ready::~get_ready()
{

}

float ini::get_ready::g_arg1(void)
{
    return (_arg1);
};

int ini::get_ready::g_arg2(void)
{
    return (_arg2);
};

int ini::get_ready::g_arg3(void)
{
    return (_arg3);
};

ini::Info::Info()
{

};

ini::Info::~Info()
{

};

int ini::Info::g_chiefs()
{
    return (this->_chief);
}

int ini::Info::g_how(void)
{
    return (_how);
};

int ini::Info::g_kitchen(void)
{
    return (_kitchen);
}

void ini::Info::tri(void)
{
    auto i = _all.begin();
    int j = 0;

    while (i != _all.end()) {
        _name.push_back(*i);
        i = i + 3;
    }
    while (j != _how * 3) {
        _nbr.push_back(_all.at(j + 2));
        _size.push_back(_all.at(j + 1));
        j = j + 3;
    }
}

void ini::Info::a_to_m(int nb)
{
    _to_m = _to_m + nb;
};

std::vector<int> ini::Info::g_num(void)
{
    return _num;
}

void ini::Info::init_info(const std::string buf)
{
    std::string tamp;
    std::vector<std::string> answer;
    int i = 0;
    std::stringstream ss(buf);

    while (ss >> tamp) {
        answer.push_back(tamp);
        i++;
    }
    _all = answer;
    _how = i/3;
    tri();
}

void ini::Info::s_num(std::vector<int> num)
{
    _num = num;
}

void ini::Info::s_to_m(int nb)
{
    _to_m = nb;
};

std::vector<std::string> ini::Info::g_name(void)
{
    return (_name);
};

int ini::Info::g_to_m(void)
{
    return (_to_m);
};

std::vector<std::string> ini::Info::g_size(void)
{
    return (_size);
};

void ini::Info::s_chiefs(int i)
{
    this->_chief = i;
}

void ini::Info::s_kitchen(int i)
{
    this->_kitchen = i;
}

std::vector<std::string> ini::Info::g_nbr(void)
{
    return (_nbr);
};
