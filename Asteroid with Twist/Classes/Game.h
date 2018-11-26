#pragma once
#include "cocos2d.h"
#include "SpaceShip.h"

class Game:public cocos2d::Scene
{
public:
	static cocos2d::Scene* Create();
	bool init() override;
	void update(const float deltaTime) override;

	

	CREATE_FUNC(Game);
private:
	cocos2d::Layer *pr_MapLayer, *pr_CameraLayer;
	SpaceShip *pr_SpaceShip;

};

