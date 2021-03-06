#pragma once
#include "GameEntities.h"
#include "State.h"
#include "GunMode.h"

class SpaceShip :
	public GameEntities
{
private:
	//Variables
	SpaceShipState *pr_CurrentState;
	GunMode *pr_CurrentGunMode;
	const float pr_Speed;
	Vector2 *pr_ForceDirection;
	int pr_Shield, pr_Cubes;

	//Functions
	void DecreaseLivesAndReset();
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
	void ResolveCollision(BlackHoles *ar_BlackHole) override;
	void ResolveCollision(PlannetEnemy *ar_Planet) override;
	void ResolveCollision(PowerUps* ar_PowerUp) override;
	void ResolveCollision(LargeAsteroid* ar_Asteroid) override;
	void ResolveCollision(EnemyBullet* ar_EnemyBullet) override;
	void ResolveCollision(KamikazeEnemy* ar_Enemy) override;
	void ResolveCollision(ShootingEnemy* ar_Enemy) override;
};
