//
// EPITECH PROJECT, 2019
// File
// File description:
// 
//

#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <vector>
#include <sstream>
#include "../Profil/Profil.hpp"
#include "../Map/Map.hpp"

class File
{
public:
        File() {
                read = std::ifstream(".data.txt");
                if (read.good())
                        _exist = true;
                else
                        _exist = false;
        };
        ~File(){};
        std::vector<std::string> loadPack();
        std::unique_ptr<Profil> write_profil(std::unique_ptr<Profil> ptr);
        std::unique_ptr<Map> write_map(std::unique_ptr<Map> ptr);
        void close_in()
        {
                read.close();
                _exist = false;
        }
//Getter
        bool getExist();
//Setter
        void setExist(bool exist);
private:
        std::vector<std::string> _pack;
        bool _exist;
        std::ifstream read;
        std::ofstream write;

};

#endif
