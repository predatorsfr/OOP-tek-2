//
// EPITECH PROJECT, 2019
// Bomberman
// File description:
// 
//

#ifndef BOMBERMAN_H
#define BOMBERMAN_H
#include <memory>
#include "Profil/Profil.hpp"
#include "File/File.hpp"
//#include "Map/Map.hpp"

class BomberMan
{
public:
        BomberMan(){
                file = std::make_unique<File>();
        };
        ~BomberMan(){};
        void load_data(int x, int y);
        void set_data(int x, int y);
        void save_data();

        std::unique_ptr<File> file;
        std::unique_ptr<Profil> profil_1;
        std::unique_ptr<Profil> profil_2;
        std::unique_ptr<Map> map;
};

#endif
