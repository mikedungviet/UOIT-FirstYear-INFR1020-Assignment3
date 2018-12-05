#include "InputDetection.h"
#include "GameEntitiesSingleton.h"
#include "SpaceShip.h"
using namespace cocos2d;

InputDetection::InputDetection()
{
	pr_Keyboard = EventListenerKeyboard::create();
	//pr_Keyboard->onKeyPressed = CC_CALLBACK_2(InputDetection::OnKeyPressed, Director::getInstance()->getRunningScene());
	//pr_Keyboard->onKeyReleased = CC_CALLBACK_2(InputDetection::OnKeyReleased, Director::getInstance()->getRunningScene());
}

void InputDetection::OnKeyPressed(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	auto lo_SpaceShip = GameEntitiesSingleton::GetInstance()->GetSpaceShip();
	switch (ar_KeyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		lo_SpaceShip->ApplyForceForward();
		break;
	case EventKeyboard::KeyCode::KEY_S:
		lo_SpaceShip->ApplyForceBackward();
		break;
	case EventKeyboard::KeyCode::KEY_A:
		lo_SpaceShip->ApplyForceLeft();
		break;
	case EventKeyboard::KeyCode::KEY_D:
		lo_SpaceShip->ApplyForceRight();
		break;
	case EventKeyboard::KeyCode::KEY_Q:
		lo_SpaceShip->RotateLeft();
		break;
	case EventKeyboard::KeyCode::KEY_E:
		lo_SpaceShip->RotateRight();
		break;
	case EventKeyboard::KeyCode::KEY_I:
		lo_SpaceShip->ChangeToSpinState();
		break;
	case EventKeyboard::KeyCode::KEY_O:
		lo_SpaceShip->ChangeToHookMode();
		break;
	case EventKeyboard::KeyCode::KEY_M:
		lo_SpaceShip->ShootBullet();
		break;
	case EventKeyboard::KeyCode::KEY_0:
		GameEntitiesSingleton::GetInstance()->GetGameEnemyVector()[0]->ChangeToActionState();
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		exit(1);
	default:
		break;
	}
}

void InputDetection::OnKeyReleased(cocos2d::EventKeyboard::KeyCode ar_KeyCode, cocos2d::Event* ar_Event)
{
	auto lo_SpaceShip = GameEntitiesSingleton::GetInstance()->GetSpaceShip();
	switch (ar_KeyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
	case EventKeyboard::KeyCode::KEY_S:
	case EventKeyboard::KeyCode::KEY_A:
	case EventKeyboard::KeyCode::KEY_D:
		lo_SpaceShip->GetMovementComponent()->SetAppliedForce(0);
		break;
	case EventKeyboard::KeyCode::KEY_Q:
		lo_SpaceShip->AddAngle(0);
		break;
	case EventKeyboard::KeyCode::KEY_E:
		lo_SpaceShip->AddAngle(0);
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		exit(1);
	default:
		break;
	}
}



