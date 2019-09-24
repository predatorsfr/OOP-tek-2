/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include "../Profil/Profil.hpp"

class music
{
public:
     music();
    ~music();
    sf::Music initialize_music();
    int play_music();
};
