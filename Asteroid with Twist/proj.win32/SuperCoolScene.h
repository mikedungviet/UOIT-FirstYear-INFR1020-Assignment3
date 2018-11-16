#pragma once
#include"cocos2d.h"

using namespace cocos2d;

class testScene : public Scene
{
public:
	//engine functions
	static Scene* createScene();
	void update(float deltatime);

	CREATE_FUNC(testScene);


};