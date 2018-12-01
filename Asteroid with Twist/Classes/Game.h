#pragma once
#include "cocos2d.h"
#include "SpaceShip.h"
#include "InputDetection.h"
#include "SmallAsteroid.h"

class Game : public cocos2d::Scene
{
private:
	cocos2d::Layer *pr_MapLayer;
	SpaceShip* pr_SpaceShip;
	cocos2d::Label *lo_Label1, *lo_Label2;
	InputDetection *lo_EventListener;
	SmallAsteroid *pr_SmallAsteroid;
public:
	static Scene* Create();
	bool init() override;

	//Member Functions
	void update(float ar_DeltaTime) override;
	void OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);
	void OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);

	CREATE_FUNC(Game);
};
