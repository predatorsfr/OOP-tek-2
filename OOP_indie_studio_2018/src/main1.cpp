/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** main
*/

#include <irrlicht/irrlicht.h>
#include "../include/Bomberman.hpp"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <cstdlib>
#include <irrlicht/driverChoice.h>
#include <vector>
using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(int ac, char **av, char **env)
{
    sf::Music music;
    sf::Window window(sf::VideoMode(50, 50), "bomberman theme");

    if (!music.openFromFile("../sound/bomberman.ogg"))
        return (84);
    else {
        music.play();
        music.setLoop(true);
    }
        irr::IrrlichtDevice *device = irr::createDevice(
        irr::video::/*EDT_OPENGL*/EDT_SOFTWARE,
        irr::core::dimension2d<irr::u32>(1920,1080),
        32, false, true, false, 0);
    irr::video::IVideoDriver* driver = device->getVideoDriver ();

    irr::scene::ISceneManager *smgr = device->getSceneManager ();

    IAnimatedMesh* mesh = smgr->getMesh("../src/Menu/Crate/Crate1.obj");
    IAnimatedMesh* mesh3 = smgr->getMesh("../src/Menu/destroy/basic_block.obj");
    IAnimatedMesh* mesh2 = smgr->getMesh("../src/Menu/cube/grass.obj");

    std::vector <IAnimatedMeshSceneNode*> node;

   smgr->addCameraSceneNode(0, vector3df(6, 2, -10), vector3df(25,80,370) );

    if (ac == 3) {
        std::unique_ptr<BomberMan> bomber(new BomberMan);
        bomber->set_data(std::atoi(av[1]), std::atoi(av[2]));
        bomber->save_data();
        bomber->map->display();
        for (int i = 0 ; i < bomber->map->getY(); i++) {
            for (int j = 0; j < bomber->map->getX(); j++) {
               if (bomber->map->getChar(i, j) == 'X') {
                    node.push_back(smgr->addAnimatedMeshSceneNode(mesh));
                    if (!node.empty()) {
                        node.back()->setPosition(core::vector3df(i * 2 ,j * 2,0));
                        node.back()->setMaterialFlag(EMF_LIGHTING, false);
                        node.back()->setMaterialTexture(0, driver->getTexture("../src/Menu/Crate/crate_1.jpg"));
                    }
                }
                if (bomber->map->getChar(i , j) == ' ') {
                     node.push_back(smgr->addAnimatedMeshSceneNode(mesh2));
                    if (!node.empty()) {
                         node.back()->setPosition(core::vector3df(i * 2,(j * 2) - 1, 2.5));
                         node.back()->setMaterialFlag(EMF_LIGHTING, false);
                         node.back()->setMaterialTexture(0, driver->getTexture("../src/Menu/cube/grass1.png"));
                         node.back()->setMaterialTexture(0, driver->getTexture("../src/Menu/cube/grass2.png"));
                    }
                }
                 if (bomber->map->getChar(i , j) == 'D') {
                     node.push_back(smgr->addAnimatedMeshSceneNode(mesh3));
                    if (!node.empty()) {
                         node.back()->setPosition(core::vector3df(i * 2,j * 2, 0));
                         node.back()->setMaterialFlag(EMF_LIGHTING, false);
                         node.back()->setMaterialTexture(0, driver->getTexture("../src/Menu/destroy/block_basic.png"));
                    }
                }
            }
        }
   }
    while (device->run ()) {

        driver->beginScene (true, true,
            irr::video::SColor (150,150,255,255));
        smgr->drawAll();
        driver->endScene();
    }
    return (0);
}
