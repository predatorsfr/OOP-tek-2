//
// EPITECH PROJECT, 2019
// Bomb
// File description:
// 
//

#include "../../include/Object/Bomb.hpp"


void Bomb::replace_hori(char **tab, char c)
{
    for (int i = _x, j = 0 ; tab[_y][i] != 'X' && j < 3 ; i++, j++)
        tab[_y][i] = c;
    for (int i = _x, j = 0 ; tab[_y][i] != 'X' && j < 3 ; i--, j++)
        tab[_y][i] = c;
}

void Bomb::replace_verti(char **tab, char c)
{
    for (int i = _y, j = 0 ; tab[i][_x] != 'X' && j < 3 ; i ++, j++)
        tab[i][_x] = c;
    for (int i = _y, j = 0; tab[i][_x] != 'X' && j < 3 ; i --, j++)
        tab[i][_x] = c;
}

void Bomb::wait()
{
    std::unique_lock<std::mutex> lock(mutex);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    _finish = true;
}
    
void Bomb::explosion(char **tab)
{
    std::unique_lock<std::mutex> lock(mutex);
    
    if (_finish) {
        tab[_y][_x] = 'E';
        replace_hori(tab, 'E');
        replace_verti(tab, 'E');
        this->~Bomb();
    }
}

bool Bomb::getFinish()
{
    std::unique_lock<std::mutex> lock(mutex);

    return (_finish);
};

int Bomb::getX()
{
    return (_x);
};

int Bomb::getY()
{
    return (_y);
};
