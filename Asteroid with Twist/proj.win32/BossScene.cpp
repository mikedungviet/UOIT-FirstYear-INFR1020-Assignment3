#include "BossScene.h"
#include "Boss.h"

Scene* BossScene::Create()
{
	auto lo_Scene = Scene::create();
	const auto lo_Layer = create();

	lo_Scene->addChild(lo_Layer);
	return lo_Scene;
}

bool BossScene::init()
{
	if (!Scene::init())
		return false;

	auto lo_Boss = new Boss;

	//Keyboard
	lo_EventListener = new InputDetection;
	lo_EventListener->pr_Keyboard->onKeyPressed = CC_CALLBACK_2(BossScene::OnKeyPressed, this);
	lo_EventListener->pr_Keyboard->onKeyReleased = CC_CALLBACK_2(BossScene::OnKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(lo_EventListener->pr_Keyboard, this);

	return true;
}

void BossScene::OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	lo_EventListener->OnKeyPressed(ar_KeyCode, ar_Event);
}

void BossScene::OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	lo_EventListener->OnKeyReleased(ar_KeyCode, ar_Event);
}
