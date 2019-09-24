//
// EPITECH PROJECT, 2019
// Load
// File description:
// 
//

//#include "Profil/Profil.hpp"
#include "../../include/Profil/Player.hpp"
#include "../../include/Profil/IA.hpp"
#include "../../include/File/File.hpp"
#include "../../include/Bomberman.hpp"

void check_file(unsigned int x, int y)
{
        std::ifstream read(".data.txt");
        std::string line;
        std::string type;
        std::string value;
        std::vector<std::string> req = {"NAME", "X", "Y", "DEATH"};
        int j = 0;

        for (int i = 0 ; i < 3 ; i++) {
                if (std::getline(read, line) && line == "PROFIL") {
                        for (int j = 0 ; std::getline(read, line) && j < 4; j++) {
                                std::stringstream ss(line);
                                std::getline(ss, type, ':');
                                std::getline(ss, value, ':');
                                if (type != req.at(j) && value == "")
                                        exit(2);
                        }
                } else if (line == "MAP") {
                        while (std::getline(read, line) && j < y) {
                                if (line.size() != x)
                                        exit(3);
                                j++;
                        }
                        if (j != (y))
                                exit(4);
                } else
                        exit(84);
        }
        read.close();
}

void BomberMan::load_data(int x, int y)
{
        std::string line;
        std::string token;
        std::vector<std::string> vec;
        bool first_profil = true;

        check_file(x, y);
        for (int i = 0 ; i < 3 ; i++) {
                vec = file->loadPack();
                if (vec.front() == "PROFIL") {
                        if (first_profil) {
                                profil_1 = std::make_unique<Player>(vec);
                                first_profil = false;
                        } else {
                                if (vec.front() == "IA")
                                        profil_2 = std::make_unique<IA>(vec);
                                else
                                        profil_2 = std::make_unique<Player>(vec);
                        }
                } else
                        if (vec.front() == "MAP")
                                map = std::make_unique<Map>(vec);
        }
        file->close_in();
}
