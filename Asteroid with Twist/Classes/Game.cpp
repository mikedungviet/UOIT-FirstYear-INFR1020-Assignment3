#include "Game.h"
#include "InputDetection.h"
using namespace cocos2d;

Scene* Game::Create()
{
	auto lo_Scene = Scene::create();
	const auto lo_Layer = create();

	lo_Scene->addChild(lo_Layer);
	return lo_Scene;
}

bool Game::init()
{
	if (!Scene::init())
		return false;

	//Big map layer. Static layer
	pr_MapLayer = Layer::create();
	this->addChild(pr_MapLayer);

	auto lo_Background = Sprite::create("TestingBackground.png");
	lo_Background->setAnchorPoint(Vec2(0.f, 0.f));
	pr_MapLayer->addChild(lo_Background);

	//Layer that will be displayed on the screen. It moves through the map layer
	//and display the part of the map
	pr_SpaceShip = new SpaceShip;
	pr_SpaceShip->SetPosition(200, 100);
	pr_MapLayer->addChild(pr_SpaceShip->GetSprite());

	//init keyboard function
	auto lo_EventListener = EventListenerKeyboard::create();
	lo_EventListener->onKeyPressed = CC_CALLBACK_2(Game::OnKeyPressed,this);
	lo_EventListener->onKeyReleased = CC_CALLBACK_2(Game::OnKeyReleased, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(lo_EventListener, this);


	//the map layer follows the spaceship
	pr_MapLayer->runAction(Follow::create(pr_SpaceShip->GetSprite()));


	//update schedule
	this->scheduleUpdate();
	return true;
}

void Game::update(const float ar_DeltaTime)
{
	pr_SpaceShip->Update(ar_DeltaTime);
}

/*
 *
 */
void Game::OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	float lo_Speed = 100;
	switch (ar_KeyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		pr_SpaceShip->GetMovementComponent()->SetAppliedForce(100);
		break;
	case EventKeyboard::KeyCode::KEY_S:
		pr_SpaceShip->GetMovementComponent()->SetForce(0, -100);
		break;
	case EventKeyboard::KeyCode::KEY_A:
		pr_SpaceShip->GetMovementComponent()->SetForce(-100, 0);
		break;
	case EventKeyboard::KeyCode::KEY_D:
		pr_SpaceShip->GetMovementComponent()->SetForce(100, 0);
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		exit(1);
	default:
		break;
	}
}

/*
 *
 */
void Game::OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	switch (ar_KeyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		pr_SpaceShip->GetMovementComponent()->SetForce(0, 0);
		break;
	case EventKeyboard::KeyCode::KEY_S:
		pr_SpaceShip->GetMovementComponent()->SetForce(0, 0);
		break;
	case EventKeyboard::KeyCode::KEY_A:
		pr_SpaceShip->GetMovementComponent()->SetForce(0, 0);
		break;
	case EventKeyboard::KeyCode::KEY_D:
		pr_SpaceShip->GetMovementComponent()->SetForce(0, 0);
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		exit(1);
	default:
		break;
	}
}



