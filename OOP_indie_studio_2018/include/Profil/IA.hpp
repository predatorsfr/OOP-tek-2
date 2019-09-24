//
// EPITECH PROJECT, 2019
// IA
// File description:
//
//

#ifndef IA_H
#define IA_H
#include "Profil.hpp"

class IA : public Profil
{
public:

    IA(std::string name,int x = 0 , int y = 0, bool death = false) : Profil(name, x , y , death){};
    IA(std::vector<std::string> ptr) : Profil(ptr) {};

//Fct

    void algo(char **tab);

};

#endif
