//
// EPITECH PROJECT, 2019
// Save
// File description:
// 
//

#include "../../include/File/File.hpp"
#include "../../include/Profil/Profil.hpp"
#include "../../include/Bomberman.hpp"

std::unique_ptr<Profil> File::write_profil(std::unique_ptr<Profil> ptr)
{
        if (!_exist) {
                remove(".data.txt");
                _exist = true;
                write = std::ofstream(".data.txt");
        }
        write << "PROFIL"<<std::endl;
        write << "NAME:" << ptr->getName() << std::endl;
        write << "X:" << ptr->getX() << std::endl;
        write << "Y:" << ptr->getY() << std::endl;
        write << "DEATH:" << ptr->getDeath() << std::endl << std::endl;
        return (ptr);
}

std::unique_ptr<Map> File::write_map(std::unique_ptr<Map> ptr)
{
        if (!_exist) {
                remove(".data.txt");
                _exist = true;
                write = std::ofstream(".data.txt");
        }
        write << "MAP"<< std::endl;
        for (int i = 0 ; i < ptr->getY() ; i++) 
        write << ptr->getLine(i) << std::endl;
        return (ptr);
}

void BomberMan::save_data()
{
        profil_1 = file->write_profil(std::move(profil_1));
        profil_2 = file->write_profil(std::move(profil_2));
        map = file->write_map(std::move(map));
}
