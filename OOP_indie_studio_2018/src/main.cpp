/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** main
*/

#include <irrlicht/irrlicht.h>
#include "../include/Bomberman.hpp"
#include "../include/Menu/Bomberman_Menu.hpp"
#include "../include/Menu/window.hpp"
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

#define MOVEMENT_SPEED 4
/*

class MyEventReceiver : public IEventReceiver
{
public:
	// This is the one method that we have to implement
	virtual bool OnEvent(const SEvent& event)
	{
		// Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

		return false;
	}

	// This is used to check whether a key is being held down
	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}
	
	MyEventReceiver()
	{
		for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
	}

private:
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};
*//*
int map_gen()
{
    MyEventReceiver receiver;
    IrrlichtDevice *device = createDevice(video::EDT_SOFTWARE, dimension2d<u32>(1920, 1080), 16, false, false, false, &receiver);
    if (!device) {
        std::cout << "Failed to init device " << std::endl;
        return 84;
    }
    device->setWindowCaption(L"NeoBomberman 2 - Map");
    u32 then = device->getTimer()->getTime();
    IVideoDriver *driver = device->getVideoDriver();
    ISceneManager *smgr = device->getSceneManager();
    IGUIEnvironment *guienv = device->getGUIEnvironment();
    IAnimatedMesh *mesh = smgr->getMesh("../Bomberman.MD3");
    if (!mesh) {
        device->drop();
        return 1;
    }
    IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);
    if (node) {
        node->setMaterialFlag(EMF_LIGHTING, false);
        node->setMD2Animation(scene::EMAT_STAND);
        node->setMaterialTexture( 0, driver->getTexture("../RedBombermanTextures.png") );
        node->setPosition({0, 0, 10});
    }
    smgr->addCameraSceneNode(0, vector3df(0,10,0), vector3df(0,0,10), -1, true);
    while(device->run()) {
        const u32 now = device->getTimer()->getTime();
    const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		then = now;
        driver->beginScene(true, true, SColor(255,100,101,140));
        smgr->drawAll();
        guienv->drawAll();
        core::vector3df nodePosition = node->getPosition();
        if(receiver.IsKeyDown(irr::KEY_UP))
			nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
		else if(receiver.IsKeyDown(irr::KEY_DOWN))
			nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
//        bomber->player1->forward();
		if(receiver.IsKeyDown(irr::KEY_LEFT))
			nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
		else if(receiver.IsKeyDown(irr::KEY_RIGHT))
			nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
        node->setPosition(nodePosition);

        driver->endScene();
    }
    device->drop();
    return (0);
}
*/
int run(char **av)
{
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
    while (device->run ()) {

        driver->beginScene (true, true,
            irr::video::SColor (150,150,255,255));
        smgr->drawAll();
        driver->endScene();
    }
    device->drop();
}

int main(int ac, char **av)
{
   // video::E_DRIVER_TYPE driverType = video::EDT_OPENGL;
    sf::Music music;
    sf::Window window(sf::VideoMode(50, 50), "bomberman theme");

    if (!music.openFromFile("../sound/bomberman.ogg"))
        return (84);
    else {
        music.play();
        music.setLoop(true);
    }
    Bomberman_Menu menu;

    if (menu.run()) {
        if (ac == 3) {
            run(av);
    //        map_gen();
        }
      //  if (av[3][0] == 'p')
        //    map_gen();
    }
    return (0);
}
