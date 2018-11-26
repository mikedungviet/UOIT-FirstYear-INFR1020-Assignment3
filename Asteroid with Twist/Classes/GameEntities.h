#pragma once
#include "CollisionComponent.h"
#include "MovementComponent.h"
#include "cocos2d.h"

class GameEntities
{
protected: //Child class inheritance variables
	CollisionComponent* pr_Collision;
	MovementComponent* pr_Movement;
	cocos2d::Sprite* pr_ObjectGraphic;
	GameEntities(const std::string& ar_FileName);
public:
	~GameEntities();

	//Getters
	cocos2d::Sprite* GetSprite();
	CollisionComponent* GetCollisionComponent();
	MovementComponent* GetMovementComponent();

	//Setters
	void SetPosition(const Vector2& ar_NewPosition) const;
	void SetPosition(const float& ar_NewX, const float& ar_NewY) const;

	//Member functions
	virtual void Update(const float& ar_DeltaTime) = 0; //Pure Virtual Function
	float CalculateSpriteRadius() const;
};
