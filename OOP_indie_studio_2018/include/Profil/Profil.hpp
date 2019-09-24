//
// EPITECH PROJECT, 2019
// zappy_test
// File description:
// 
//

#ifndef PROFIL_H
#define PROFIL_H

#include <sstream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <iostream>


class Profil
{
public:
        Profil(std::string name,int x = 0 , int y = 0, bool death = false) : _name(name)
        {
                _x = x;
                _y = y;
                _death = death;
        };

        Profil(std::vector<std::string> vec)
        {
                if (vec.back() == "true")
                        _death = true;
                else
                        _death = false;
                vec.pop_back();
                _y = std::stod(vec.back());
                vec.pop_back();
                _x = std::stod(vec.back());
                vec.pop_back();
                _name = vec.back();
        }
        ~Profil(){};
        bool forward(char **tab);
        bool downward(char **tab);
        bool right(char **tab);
        bool left(char **tab);

//Setter
        void setX(int x);
        void setY(int y);
        void setDeath(bool death);

//Getter
        std::string getName(){
                return(_name);
        };
        int getX(){
                return (_x);
        };
        int getY(){
                return(_y);
        };
        bool getDeath(){
                return (_death);
        };

        void display()
        {
        std::cout << _name << std::endl;
        std::cout << _x << "," << _y << std::endl;
        std::cout << _death << std::endl;
        }
protected:
        std::string _name;
        int _x;
        int _y;
        bool _death;
};

#endif
