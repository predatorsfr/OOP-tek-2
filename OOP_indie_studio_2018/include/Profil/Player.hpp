//
// EPITECH PROJECT, 2019
// Player
// File description:
// 
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../Profil/Profil.hpp"

class Player : public Profil
{
public:
    Player(std::string name,int x = 0 , int y = 0, bool death = false) : Profil(name, x , y , death){};
    Player(std::vector<std::string> ptr) : Profil(ptr) {};
};

#endif
