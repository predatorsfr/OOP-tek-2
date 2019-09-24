/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** my.hpp
*/

#ifndef MY_HPP_
#define MY_HPP_

#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <unistd.h>
#include <sys/types.h>
#include <thread>
#include <bits/stdc++.h>
#include <sys/msg.h>
#include <sys/ipc.h>

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};


/***************/
//    CLASS    //
/***************/

namespace ini {
    class get_ready {
    public:
        get_ready(float, int, int);
        ~get_ready();
        float g_arg1(void);
        int g_arg2(void);
        int g_arg3(void);
    private:
        const float _arg1;
        const int _arg2;
        const int _arg3;
            };
    class Info {
    public:
        int g_how(void);
        void s_to_m(int);
        void a_to_m(int);
        int g_to_m(void);
        void s_kitchen(int);
        void s_chiefs(int);
        void s_num(std::vector<int>);
        int g_kitchen(void);
        int g_chiefs(void);
        std::vector<int> g_num(void);
        Info();
        ~Info();
        void init_info(const std::string);
        std::vector<std::string> g_name(void);
        std::vector<std::string> g_size(void);
        std::vector<std::string> g_nbr(void);
    private:
        void tri(void);
        int _how;
        int _to_m;
        std::vector<std::string> _name;
        std::vector<std::string> _all;
        std::vector<std::string> _size;
        std::vector<std::string> _nbr;
        std::vector<int> _num;
        int _cheese;
        int _egg;
        int _steak;
        int _mushroom;
        int _ham;
        int _gruyere;
        int _tomato;
        int _doe;
        int _pizza;
        int _chief;
        int _kitchen;
    };
}



/****************/
//   FUNCTION   //
/****************/

int fork(ini::Info *info, ini::get_ready get_ready);
int loop(ini::Info *info, std::string tamp, ini::get_ready get_ready);
int init_arg(std::string arg1, std::string arg2, std::string arg3);
int check_name(std::string buf);
int check_type(std::string buf, int i);
int check_size(ini::Info info, std::vector<std::string> size);
int check_nbr(ini::Info info);
#endif
