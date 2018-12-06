#pragma once
#include "Enemies.h"


class Boss :
	public Enemies
{
private:
	int ShootingSpeed;
	int Health;
public:
	Boss();
	~Boss();

	//Updating Functions
	void Update(const float& ar_DeltaTime) override;
	void ChangeToIdleState() override;
	void ChangeToActionState() override;
	static bool bossSpawned;
	void ChangeState();

	//Resolving Collision
	void ResolveCollision(GameEntities* ar_Entity) override;
	void ResolveCollision(ShipBullet* ar_Bullet) override;
};

