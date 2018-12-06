#pragma once
#include "cocos2d.h"
#include "InputDetection.h"

using namespace cocos2d;

class BossScene: public cocos2d::Scene
{
private:
	InputDetection *lo_EventListener;
public:
	static Scene* Create();
	bool init() override;

	void OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);
	void OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);

	CREATE_FUNC(BossScene);
};

