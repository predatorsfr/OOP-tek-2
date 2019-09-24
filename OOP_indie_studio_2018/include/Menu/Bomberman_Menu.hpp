/*
** EPITECH PROJECT, 2019
** include
** File description:
** indie
*/


#pragma once
#include <irrlicht/irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Bomberman_Menu : public IEventReceiver
{
public:

	Bomberman_Menu();

	bool run(void);

	virtual bool OnEvent(const SEvent& event);

private:
	gui::IGUIButton* startButton;
	gui::IGUIButton* Save_load;
	IrrlichtDevice *device;
	s32 selected;
	bool start;
};

