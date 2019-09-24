//
// EPITECH PROJECT, 2019
// File
// File description:
// 
//

#include "../../include/File/File.hpp"

bool File::getExist(void)
{
        return (_exist);
}

void File::setExist(bool exist)
{
        _exist = exist;
}

std::vector<std::string> File::loadPack()
{
        std::string line;
        std::string token;
        std::vector <std::string> vec;

        while (std::getline(read, line) && line != "") {
                if (line == "MAP" || line == "PROFIL")
                        vec.push_back(line);
                else {
                        std::stringstream ss(line);
                        std::getline(ss, token, ':');
                        std::getline(ss, token, ':');
                        vec.push_back(token);
                }
        }
        return (vec);
}
