#include "Game.h"
#include "InputDetection.h"
#include "GameEntitiesSingleton.h"
#include "CollisionDetection.h"
#include "BlackHolesSingleton.h"
#include "ShootingEnemy.h"
#include "KamikazeEnemy.h"
#include "PlannetEnemy.h"

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
	GameEntitiesSingleton::GetInstance()->AddEntity(pr_SpaceShip);
	GameEntitiesSingleton::GetInstance()->SetSpaceShip(pr_SpaceShip);

	
	pr_ShootingEnemy = new ShootingEnemy;
	for (int i = 0; i < 3; i++)
	{
		auto pr_PlanetEnemy = new PlannetEnemy;
	}
	for (int i = 0; i < 3; i++)
	{
		auto pr_BlackHoles = new BlackHoles;
	}

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

	if(LargeAsteroid::count < 100)
	{
		auto pr_LargeAsteroid = new LargeAsteroid;
		LargeAsteroid::count++;
	}
	if(KamikazeEnemy::count < 10)
	{
		auto pr_KamikazeEnemy = new KamikazeEnemy;
		KamikazeEnemy::count++;
	}
	if(ShootingEnemy::count < 10)
	{
		auto pr_ShootingEnemy = new ShootingEnemy;
		ShootingEnemy::count++;
	}

	//Loop through each black hole and game entity to apply force to the game entity
	for (auto lo_I : BlackHolesSingleton::GetInstance()->GetBlackHoleVector())
	{
		for (auto lo_J : GameEntitiesSingleton::GetInstance()->GetGameEntitiesVector())
		{
			lo_I->AddAdditionalForceToEntity(lo_J);
		}
	}

	//Update all Objects
	for(unsigned lo_I=0; lo_I < GameEntitiesSingleton::GetInstance()->GetGameEntitiesVector().size(); lo_I++)
	{
		GameEntitiesSingleton::GetInstance()->GetGameEntitiesVector()[lo_I]->Update(ar_DeltaTime);
	}

	//Update all enemies States depends on the position of the ship
	for(auto lo_I : GameEntitiesSingleton::GetInstance()->GetGameEnemyVector())
	{
		if (Vector2::CalculateDistanceSquareBetweenTwoVectors(*lo_I->GetCollisionComponent()->GetPosition(),
			*pr_SpaceShip->GetCollisionComponent()->GetPosition()) < std::pow(lo_I->GetActionRange(),2))
		{
			lo_I->ChangeToActionState();
		}
		else
			lo_I->ChangeToIdleState();
	}

	//Detect and Resolve Collision
	CollisionDetection::LoopAndDetectCollision();

	if (GameEntitiesSingleton::GetInstance()->GetSpaceShip() == nullptr)
	{
		exit(1);
	}
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