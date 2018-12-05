#pragma once
#include "Enemies.h"


class ShootingEnemy :
	public Enemies
{
public:
	ShootingEnemy();
	~ShootingEnemy();

	//Updating Functions
	void Update(const float& ar_DeltaTime) override;
	void ChangeToIdleState() override;
	void ChangeToActionState() override;


	//Resolving Collision
	void ResolveCollision(GameEntities* ar_Entity) override;
};

