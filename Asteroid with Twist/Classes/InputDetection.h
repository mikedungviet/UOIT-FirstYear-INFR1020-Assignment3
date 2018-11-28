#pragma once
#include "cocos2d.h"
#include "GameEntities.h"

class InputDetection
{
public:
	static void OnKeyPressed(GameEntities *ar_GameEntity);
	static void OnKeyReleased(GameEntities *ar_GameEntity){}
};

