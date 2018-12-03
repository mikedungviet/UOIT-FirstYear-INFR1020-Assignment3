#pragma once
#include "cocos2d.h"
#include "SpaceShip.h"
#include "InputDetection.h"
#include "SmallAsteroid.h"
#include "BlackHoles.h"

class Game : public cocos2d::Scene
{
private:
	cocos2d::Layer *pr_MapLayer;
	SpaceShip* pr_SpaceShip;
	InputDetection *lo_EventListener;
	SmallAsteroid *pr_SmallAsteroid;
	BlackHoles *pr_BlackHoles;
public:
	static Scene* Create();
	bool init() override;

	//Member Functions
	void update(float ar_DeltaTime) override;
	void OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);
	void OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);

	CREATE_FUNC(Game);
};
