#pragma once
#include "cocos2d.h"
#include "SpaceShip.h"

class Game : public cocos2d::Scene
{
public:
	static Scene* Create();
	bool init() override;
	void update(float deltaTime) override;


	CREATE_FUNC(Game);
private:
	cocos2d::Layer *pr_MapLayer, *pr_CameraLayer;
	SpaceShip* pr_SpaceShip;
};
