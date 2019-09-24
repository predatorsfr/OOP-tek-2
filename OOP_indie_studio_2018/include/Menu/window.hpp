#pragma once

#include <irrlicht/irrlicht.h>


using namespace irr;

class CWindow : public IEventReceiver
{
public:

	CWindow(video::E_DRIVER_TYPE driver);

	~CWindow();

	void run();
	virtual bool OnEvent(const SEvent& event);

private:
	void switchToNextScene();

	video::E_DRIVER_TYPE driverType;
	IrrlichtDevice *device;

	gui::IGUIButton* S_button;
	gui::IGUIButton* M_button;
	int currentScene;
	bool start;
	s32 sceneStartTime;
	s32 timeForThisScene;
};

