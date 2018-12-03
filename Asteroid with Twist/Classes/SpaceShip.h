#pragma once
#include "GameEntities.h"
#include "State.h"
#include "GunMode.h"

class SpaceShip :
	public GameEntities
{
private:
	SpaceShipState *pr_CurrentState;
	GunMode *pr_CurrentGunMode;
	const float pr_Speed;
	Vector2 *pr_ForceDirection;

	int pr_Shield, pr_Lives;
public:
	//Constructors and Destructor
	SpaceShip();
	~SpaceShip();

	//Getters
	Vector2* GetForceDirection() const;
	float GetSpeed() const;

	//Setters
	void SetState(SpaceShipState *ar_NewState);
	void SetGunMode(GunMode *ar_NewMode);

	//Member Functions
	void Update(const float& ar_DeltaTime) override;

	//State Changer
	void ChangeToNormalState();
	void ChangeToSpinState();
	void ChangeToHookState();
	void ChangeToNormalMode();
	void ChangeToHookMode();

	//Movement
	void ApplyForceForward() ;
	void ApplyForceBackward();
	void ApplyForceLeft();
	void ApplyForceRight();
	void RotateLeft();
	void RotateRight();
	void ShootBullet();

	//Collision Resolver
	void ResolveCollision(GameEntities* ar_Entity) override;
	void ResolveCollision(SmallAsteroid* ar_SmallAsteroid) override;
	
};
