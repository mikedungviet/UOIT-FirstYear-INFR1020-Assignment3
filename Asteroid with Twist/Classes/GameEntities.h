#pragma once
#include "CollisionComponent.h"
#include "MovementComponent.h"
#include "cocos2d.h"

//All entity
class ShipBullet;
class SpaceShip;
class SmallAsteroid;
class LargeAsteroid;
class GrapplingHookBullet;
class BlackHoles;
class EnemyBullet;
class PowerUps;

class GameEntities
{
private:
	float CalculateSpriteRadius() const;
protected: //Child class inheritance variables
	float *pr_Theta;
	CollisionComponent* pr_Collision;
	MovementComponent* pr_Movement;
	cocos2d::Sprite* pr_ObjectGraphic;
	int pr_Lives;
	GameEntities(const std::string& ar_FileName);
public:
	virtual ~GameEntities();

	//Getters
	cocos2d::Sprite* GetSprite() const;
	CollisionComponent* GetCollisionComponent() const;
	MovementComponent* GetMovementComponent() const;
	float* GetAngle() const;
	int GetLives()const;

	//Setters
	void SetPosition(const Vector2& ar_NewPosition) const;
	void SetPosition(const float& ar_NewX, const float& ar_NewY) const;

	//Member functions
	virtual void Update(const float& ar_DeltaTime);
	void CheckPositionOutOfMap() const;
	void AddAngle(const float& ar_Angle) const;
	void ChangeEntityDirection(Vector2 & ar_NewDirection);
	
	//Collision Resolver
	virtual void ResolveCollision(GameEntities *ar_Entity) = 0;
	virtual void ResolveCollision(ShipBullet *ar_Bullet) {}
	virtual void ResolveCollision(SmallAsteroid *ar_SmallAsteroid) {}
	virtual void ResolveCollision(LargeAsteroid *ar_LargeAsteroid) {}
	virtual void ResolveCollision(SpaceShip *ar_SpaceShip){}
	virtual void ResolveCollision(GrapplingHookBullet *ar_Hook){}
	virtual void ResolveCollision(BlackHoles *ar_BlackHole);
	virtual void ResolveCollision(PowerUps* ar_PowerUp) {}
};
