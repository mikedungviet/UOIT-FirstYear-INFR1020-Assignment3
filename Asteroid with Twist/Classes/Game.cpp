#include "Game.h"
#include "InputDetection.h"
#include "GameEntitiesSingleton.h"
#include "CollisionDetection.h"
#include "BlackHolesSingleton.h"
#include "ShootingEnemy.h"

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
	GameEntitiesSingleton::GetInstance()->SetMapLayer(pr_MapLayer);
	BlackHolesSingleton::GetInstance()->SetMapLayer(pr_MapLayer);

	auto lo_Background = Sprite::create("TestingBackground.png");
	lo_Background->setAnchorPoint(Vec2(0.f, 0.f));
	pr_MapLayer->addChild(lo_Background);

	//Layer that will be displayed on the screen. It moves through the map layer
	//and display the part of the map
	pr_SpaceShip = new SpaceShip;
	pr_SpaceShip->SetPosition(200, 100);
	pr_MapLayer->addChild(pr_SpaceShip->GetSprite());
	GameEntitiesSingleton::GetInstance()->SetSpaceShip(pr_SpaceShip);

	//
	pr_ShootingEnemy = new ShootingEnemy;

	//init keyboard function
	lo_EventListener = new InputDetection;
	lo_EventListener->pr_Keyboard->onKeyPressed = CC_CALLBACK_2(Game::OnKeyPressed, this);
	lo_EventListener->pr_Keyboard->onKeyReleased = CC_CALLBACK_2(Game::OnKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(lo_EventListener->pr_Keyboard, this);

	//the map layer follows the spaceship
	pr_MapLayer->runAction(Follow::create(pr_SpaceShip->GetSprite()));

	//update schedule
	this->scheduleUpdate();
	return true;
}

void Game::update(const float ar_DeltaTime)
{
	auto lo_TempVec = GameEntitiesSingleton::GetInstance()->GetGameEntitiesVector();
	pr_SpaceShip->Update(ar_DeltaTime);


	//Update all Objects
	for(unsigned lo_I=0; lo_I < GameEntitiesSingleton::GetInstance()->GetGameEntitiesVector().size(); lo_I++)
	{
		GameEntitiesSingleton::GetInstance()->GetGameEntitiesVector()[lo_I]->Update(ar_DeltaTime);
	}

	//Update all enemies States
	
	//Detect and Resolve Collision
	CollisionDetection::LoopAndDetectCollision();

}

/*
 *@brief This function process any user input key press.
 */
void Game::OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	lo_EventListener->OnKeyPressed(ar_KeyCode, ar_Event);
}

/*
 *@brief 
 */
void Game::OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	lo_EventListener->OnKeyReleased(ar_KeyCode, ar_Event);
}