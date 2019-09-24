//
// EPITECH PROJECT, 2019
// Profil
// File description:
// 
//

//#include "Profil/Profil.hpp"
#include "../../include/Profil/Player.hpp"
#include "../../include/Profil/IA.hpp"
#include "../../include/File/File.hpp"
#include "../../include/Bomberman.hpp"

void BomberMan::set_data(int x, int y)
{
        if (file->getExist())
                load_data(x, y);
        else {
                profil_1 = std::make_unique<Player> ("name_user");
                profil_2 = std::make_unique<IA>("IA");
                map = std::make_unique<Map>(x, y);
        }
}

bool Profil::forward(char **map)
{
    if(map[_x++][_y] == 'x')
	return(false);
    if(map[_x++][_y] == 'o')
        return(false);
    _x++;
    return(true);
};

bool Profil::downward(char **map)
{
    if(map[_x--][_y] == 'x')
	return(false);
    if(map[_x--][_y] == 'o')
	return(false);
    _x--;
    return(true);
};

bool Profil::right(char **map)
{
    if(map[_x][_y++] == 'x')
        return(false);
    if(map[_x][_y++] == 'o')
	return(false);
    _y++;
    return(true);
};

bool Profil::left(char **map)
{
    if(map[_x][_y--] == 'x')
        return(false);
    if(map[_x][_y--] == 'o')
	return(false);
    _y--;
    return(true);
};






