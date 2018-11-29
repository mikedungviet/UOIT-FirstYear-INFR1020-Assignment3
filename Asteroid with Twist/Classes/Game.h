#pragma once
#include "cocos2d.h"
#include "SpaceShip.h"

class Game : public cocos2d::Scene
{
private:
	cocos2d::Layer *pr_MapLayer, *pr_CameraLayer;
	SpaceShip* pr_SpaceShip;
public:
	static Scene* Create();
	bool init() override;

	//Member Functions
	void update(float ar_DeltaTime) override;
	void OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);
	void OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);

	CREATE_FUNC(Game);
};
