#pragma once
#include "cocos2d.h"

class InputDetection
{
	
public:
	InputDetection();
	void OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);
	void OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event);
	cocos2d::EventListenerKeyboard *pr_Keyboard;
};

