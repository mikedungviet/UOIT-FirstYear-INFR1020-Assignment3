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
	//pr_SpaceShip->GetMovementComponent()->SetAppliedForce(100);
	pr_MapLayer->addChild(pr_SpaceShip->GetSprite());

	//init keyboard function
	auto lo_EventListener = EventListenerKeyboard::create();
	lo_EventListener->onKeyPressed = CC_CALLBACK_2(Game::OnKeyPressed,this);
	lo_EventListener->onKeyReleased = CC_CALLBACK_2(Game::OnKeyReleased, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(lo_EventListener, this);


	//the map layer follows the spaceship
	pr_MapLayer->runAction(Follow::create(pr_SpaceShip->GetSprite()));

	//create a testing label
	lo_Label1 = Label::createWithSystemFont("X: ", "Time News Roman", 50);
	lo_Label1->setAnchorPoint(Vec2(0.0, 0.0));
	this->addChild(lo_Label1);

	lo_Label2 = Label::createWithSystemFont("Y: ", "Time News Roman", 50);
	lo_Label2->setAnchorPoint(Vec2(0.0, 0.0));
	lo_Label2->setPosition(0, 51);
	this->addChild(lo_Label2);

	//update schedule
	this->scheduleUpdate();
	return true;
}

void Game::update(const float ar_DeltaTime)
{
	pr_SpaceShip->Update(ar_DeltaTime);
	const auto lo_X = *(pr_SpaceShip->GetAngle());
	const auto lo_Y = pr_SpaceShip->GetMovementComponent()->GetVelocity()->y;

	lo_Label1->setString("Velocity X: "+ std::to_string(lo_X));
	lo_Label2->setString("Velocity Y: " + std::to_string(lo_Y));
}

/*
 *@brief This function process any user input key press.
 */
void Game::OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	switch (ar_KeyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		pr_SpaceShip->ApplyForceForward();
		break;
	case EventKeyboard::KeyCode::KEY_S:
		pr_SpaceShip->ApplyForceBackward();
		break;
	case EventKeyboard::KeyCode::KEY_A:
		pr_SpaceShip->ApplyForceLeft();
		break;
	case EventKeyboard::KeyCode::KEY_D:
		pr_SpaceShip->ApplyForceRight();
		break;
	case EventKeyboard::KeyCode::KEY_Q:
		pr_SpaceShip->RotateLeft();
		break;
	case EventKeyboard::KeyCode::KEY_E:
		pr_SpaceShip->RotateRight();
		break;
	case EventKeyboard::KeyCode::KEY_I:
		pr_SpaceShip->ChangeToSpinState();
		break;
	case EventKeyboard::KeyCode::KEY_O:
		pr_SpaceShip->ChangeToNormalState();
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		exit(1);
	default:
		break;
	}
}

/*
 *@brief 
 */
void Game::OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	switch (ar_KeyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
	case EventKeyboard::KeyCode::KEY_S:
	case EventKeyboard::KeyCode::KEY_A:
	case EventKeyboard::KeyCode::KEY_D:
		pr_SpaceShip->GetMovementComponent()->SetAppliedForce(0);
		break;
	case EventKeyboard::KeyCode::KEY_Q:
		pr_SpaceShip->AddAngle(0);
		break;
	case EventKeyboard::KeyCode::KEY_E:
		pr_SpaceShip->AddAngle(0);
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		exit(1);
	default:
		break;
	}
}