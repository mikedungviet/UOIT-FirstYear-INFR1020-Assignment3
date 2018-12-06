#pragma once
#include "Enemies.h"


class ShootingEnemy :
	public Enemies
{
public:
	ShootingEnemy();
	~ShootingEnemy();

	static unsigned int count;
	//Updating Functions
	void Update(const float& ar_DeltaTime) override;
	void ChangeToIdleState() override;
	void ChangeToActionState() override;


	//Resolving Collision
	void ResolveCollision(GameEntities* ar_Entity) override;
	void ResolveCollision(SpaceShip *ar_Ship) override;
	void ResolveCollision(ShipBullet *ar_Bullet) override;
};

