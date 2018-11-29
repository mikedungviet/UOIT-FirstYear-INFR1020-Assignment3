#pragma once
#include "CollisionComponent.h"
#include "MovementComponent.h"
#include "cocos2d.h"

class GameEntities
{
private:
	float CalculateSpriteRadius() const;
protected: //Child class inheritance variables
	float *pr_Theta;
	CollisionComponent* pr_Collision;
	MovementComponent* pr_Movement;
	cocos2d::Sprite* pr_ObjectGraphic;
	GameEntities(const std::string& ar_FileName);
public:
	~GameEntities();

	//Getters
	cocos2d::Sprite* GetSprite() const;
	CollisionComponent* GetCollisionComponent() const;
	MovementComponent* GetMovementComponent() const;
	float* GetAngle() const;

	//Setters
	void SetPosition(const Vector2& ar_NewPosition) const;
	void SetPosition(const float& ar_NewX, const float& ar_NewY) const;

	//Member functions
	virtual void Update(const float& ar_DeltaTime);
	void CheckPositionOutOfMap() const;
	void AddAngle(const float& ar_Angle) const;

	//Static Function
	static void CheckPositionOutOfMap(GameEntities *ar_GameEntities);
};
