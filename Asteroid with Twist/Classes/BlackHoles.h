#pragma once
#include "CollisionComponent.h"
#include "cocos2d.h"

class BlackHoles
{
private:
	//Variables
	CollisionComponent* pr_Collision;
	cocos2d::Sprite *pr_Sprite;
	const float pr_AffectedDistance;

	//Functions
	float CalculateSpriteRadius() const;
public:
	BlackHoles();
	~BlackHoles();

	//Getters
	CollisionComponent* GetCollision() const;
	cocos2d::Sprite* GetSprite() const;

	//Setters
	void SetPosition(const Vector2& ar_NewPosition) const;
	void SetPosition(const float& ar_NewX, const float& ar_NewY) const;

	//Member functions
	Vector2 CalculateAddingForce(const CollisionComponent* ar_EntityCollisionComponent){}
};

