/*
** EPITECH PROJECT, 2019
** d08
** File description:
** this is the ex00
*/

#include "../../include/Map/Map.hpp"
#include <vector>
#include <string.h>
#include <string>
#include <cstring>

Map::~Map()
{
}

Map::Map(std::vector<std::string> ptr) : _x(ptr.back().size()), _y(ptr.size() - 1)
{
    map = new char*[_y + 1];
    map[_y] = NULL;
    for (int y = 0 ; y < _y ; y++) {
        map[y] = new char[_x + 1];
        std::strcpy(map[y], ptr.at(y+1).c_str());
    }
}

int Map::gen_rand()
{
    int random;

    std::srand(std::time(nullptr));
    random = std::rand() %6;
    return (random);
}

void Map::create_map()
{
    this->map = new char*[_y + 1];

    map[_y] = NULL;
    for (int i = 0; i < _y; i++) {
        map[i] = new char[_x + 1];
        map[i][_x] = '\0';
    }
    for (int i = 0; i < _x; i++)
        map[0][i] = 'X';
    for (int i = 1; i < _y; i++) {
        map[i][0] = 'X';
        for (int c = 1; c < _x; c++)
            map[i][c] = ' ';
        map[i][_x - 1] = 'X';
        }
    for (int i = 0; i < _x; i++)
        map[_y - 1][i] = 'X';
}

void Map::put_destructibles()
{
    for (int i = 0; map[i] != NULL; i++)
        for (int c = 0; c < _x; c++)
            if (map[i][c] != 'X' && map[i][c] == ' ' && map[i][c - 1] != 'D')
                map[i][c] = 'D';
}

void Map::rand_empty()
{
    int rand = std::rand() %10;

    std::srand(std::time(nullptr));
    for (int i = 0; map[i] != NULL; i++) {
        for (int c = 0; map[i][c] != '\0'; c++) {
            rand = std::rand() %10;
            if (map[i][c] == 'D' && rand > 5)
                map[i][c] = ' ';
        }
    }
}

void Map::gen_obstacle()
{
    int check = 0;

    for (int i = 2; map[i] != NULL; i++)
        for (int c = 0; map[i][c] != '\0'; c++) {
            if (check == 0 && map[i + 2] == NULL)
                check = 1;
            if (check == 0 && map[i][c] != 'X' && map[i][c] == ' ' && map[i][c - 1] != 'X')
                map[i][c] = 'X';
        }
}

void Map::gen_map()
{

    create_map();
    put_destructibles();
    rand_empty();
    gen_obstacle();
}

void Map::display()
{
    for (int i = 0; map[i] != NULL; i++)
        std::cout << map[i] << std::endl;
}

void Map::setBomb(int x, int y)
{
    bombers.push_back(std::make_unique<Bomb>(x, y, map));
}

