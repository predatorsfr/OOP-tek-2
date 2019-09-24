//
// EPITECH PROJECT, 2019
// Bomb
// File description:
// 
//

#ifndef BOMB_H
#define BOMB_H
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>

class Bomb
{
public:
    void wait();
    void replace_hori(char **tab, char c);
    void replace_verti(char **tab, char c);
    Bomb(int x, int y, char **tab) : _x(x), _y(y){
        _finish = false;
        tab[y][x] = 'B';
        replace_hori(tab, 'D');
        replace_verti(tab, 'D');
        _thread = std::thread(&Bomb::wait, this);
    };
    ~Bomb(){
        _thread.join();
    };
    void explosion(char **tab);

    bool getFinish();
    int getX();
    int getY();
private:
    std::mutex mutex;
    std::thread _thread;
    bool _finish;
    const int _x;
    const int _y;
};

#endif
