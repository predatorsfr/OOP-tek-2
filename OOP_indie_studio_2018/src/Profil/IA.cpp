/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** ia.cpp
*/

#include "../../include/Profil/IA.hpp"
#include "../../include/Map/Map.hpp"
#include <vector>
#include <string.h>
#include <string>
#include <cstring>

void IA::algo(char **map)
{
    while(_death != true) {
        while(map[_x][_y] == 'D') {
            if(forward(map) == false)
            for(int i = 3; i != 0; i--)
                if(left(map) == false)
                    right(map);
        }
        for(int i = std::rand() % 3 + 1; i != 0; i--)
            right(map);
        for(int i = std::rand() % 5 + 1; i != 0; i--)
            downward(map);
        //bomb
    }
};
