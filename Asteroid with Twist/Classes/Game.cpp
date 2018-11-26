#include "Game.h"
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
	pr_SpaceShip->SetPosition(500, 500);
	pr_MapLayer->addChild(pr_SpaceShip->GetSprite());


	//Testing Label
	auto lo_Label = Label::createWithSystemFont(
		"X: " + std::to_string((*pr_SpaceShip->GetCollisionComponent()->GetRadius())), "Times New Roman", 50);
	lo_Label->setAnchorPoint(Vec2(0.f, 0.f));
	this->addChild(lo_Label);


	//update schedule
	this->scheduleUpdate();
	return true;
}

void Game::update(const float deltaTime)
{
	(*pr_SpaceShip->GetMovementComponent()->GetForce()).x = 100;
	pr_SpaceShip->Update(deltaTime);
}
