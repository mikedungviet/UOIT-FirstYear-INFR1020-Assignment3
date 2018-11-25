#pragma once
#include "cocos2d.h"

class Game:public cocos2d::Scene
{
public:
	static cocos2d::Scene* Create();
	bool init() override;
	void update(const float deltaTime) override;

	

	CREATE_FUNC(Game);
private:
	cocos2d::Layer *pr_MapLayer, *pr_CameraLayer;
	cocos2d::Sprite *pr_SpaceShip;
	cocos2d::Camera *pr_Camera;

};

