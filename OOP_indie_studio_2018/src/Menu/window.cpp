#include "../../include/Menu/window.hpp"

CWindow::CWindow(video::E_DRIVER_TYPE d)
: driverType(d), device(0), currentScene(-2),sceneStartTime(0), timeForThisScene(0)
{
}

CWindow::~CWindow()
{}

void CWindow::run()
{
	core::dimension2d<u32> resolution (800, 600);

	if ( driverType == video::EDT_BURNINGSVIDEO || driverType == video::EDT_SOFTWARE )
	{
		resolution.Width = 640;
		resolution.Height = 480;
	}

	irr::SIrrlichtCreationParameters params;
	params.DriverType=driverType;
	params.WindowSize=resolution;

	device = createDeviceEx(params);
	if (!device)
		return;

	video::IVideoDriver* driver = device->getVideoDriver();
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
	irr::scene::ISceneManager *sceneManager = device->getSceneManager ();
	irr::gui::IGUIEnvironment *gui = sceneManager->getGUIEnvironment();

	gui->addButton(core::rect<int>(110, 300, 210, 310), 0, -1, L"S_Button");
	//irr::gui::IGUIButton *M_button = gui->addButton(core::rect<int>(600, 620, 700, 650),0, 2, L"M_Button");

	device->setWindowCaption(L"Bomberman");
	while(device->run() && driver)
	{
		if (device->isWindowActive())
		{
			sceneManager->drawAll();
			gui->drawAll();
			sceneManager->drawAll();
			guienv->drawAll();
			driver->endScene();
		}
	}
	device->drop();
}


bool CWindow::OnEvent(const SEvent& event)
{
	if (!device)
		return false;

	if (event.EventType == EET_KEY_INPUT_EVENT &&
		event.KeyInput.Key == KEY_ESCAPE &&
		event.KeyInput.PressedDown == false)
			device->closeDevice();
	return false;
}


