#include "Game.h"
using namespace cocos2d;

cocos2d::Scene* Game::Create()
{
	auto lo_Scene = Scene::create();
	auto lo_Layer = Game::create();

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
	pr_CameraLayer = Layer::create();
	this->addChild(pr_CameraLayer);
	pr_CameraLayer->setPosition(ccpAdd(Vec2(100, 100), Vec2(100, 100)));


	//Creating a Sprite
	/*pr_SpaceShip = Sprite::create("Ship.png");
	pr_SpaceShip->setPosition(500, 500);
	pr_CameraLayer->addChild(pr_SpaceShip);*/


	//Testing Label
	auto lo_Label = Label::createWithSystemFont("X: " + std::to_string(pr_CameraLayer->getPositionX()) , "Times New Roman", 50);
	lo_Label->setAnchorPoint(Vec2(0.f, 0.f));
	this->addChild(lo_Label);


	//update schedule
	this->scheduleUpdate();
	return true;
}

void Game::update(const float deltaTime)
{
	/*auto lo_Position = pr_SpaceShip->getPosition();
	lo_Position.x += 200 * deltaTime;
	pr_SpaceShip->setPosition(lo_Position);*/
}
