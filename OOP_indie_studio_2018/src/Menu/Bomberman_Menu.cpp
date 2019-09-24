/*
** EPITECH PROJECT, 2019
** menu
** File description:
** indie
*/


#include "../../include/Menu/Bomberman_Menu.hpp"
#include "irrlicht/driverChoice.h"

Bomberman_Menu::Bomberman_Menu(): startButton(0), Save_load(0),device(0), selected(2), start(false)
{
}

bool Bomberman_Menu::run(void)
{
	video::E_DRIVER_TYPE driverType= video::EDT_OPENGL;
	device = createDevice(driverType, core::dimension2d<u32>(1620, 720), 16, false, false, false, this);

	video::IVideoDriver* driver = device->getVideoDriver();
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
	ITexture *image = driver->getTexture("../src/Menu/bomb.jpg");
	startButton = guienv->addButton(core::rect<int>(700, 620, 800, 650), 0, 2, L"Bomberman");
	Save_load = guienv->addButton(core::rect<int>(600, 620, 700, 650),0, 2, L"Save Load");

	while(device->run()) {
		if (device->isWindowActive()) {
			driver->beginScene(false, true, video::SColor(0,0,0,0));
			driver->draw2DImage(image, irr::core::position2d<irr::s32>(0,0), irr::core::rect<irr::s32>(0,0,1280,700),0, irr::video::SColor(255,255,255,255), true);
			guienv->drawAll();
			driver->endScene();
		}
	}

	device->drop();
	return start;
}

bool Bomberman_Menu::OnEvent(const SEvent& event)
{
	if (event.EventType == EET_GUI_EVENT) {
		s32 id = event.GUIEvent.Caller->getID();
		if (id) {
			if (id == 1) {
				if (event.GUIEvent.EventType == gui::EGET_LISTBOX_CHANGED ||
					event.GUIEvent.EventType == gui::EGET_LISTBOX_SELECTED_AGAIN) {
					selected = ((gui::IGUIListBox*)event.GUIEvent.Caller)->getSelected();
					startButton->setEnabled(true);
					Save_load->setEnabled(true);
				}
			} else if (id == 2) {
				if (event.GUIEvent.EventType == gui::EGET_BUTTON_CLICKED ) {
					device->closeDevice();
					start = true;
				}
			}
		}
	}
	return false;
}
