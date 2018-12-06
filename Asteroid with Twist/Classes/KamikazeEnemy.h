#pragma once
#include "Enemies.h"

class KamikazeEnemy :
	public Enemies
{
public:
	KamikazeEnemy();
	~KamikazeEnemy();

	static unsigned int count;

	void Update(const float& ar_DeltaTime) override;

	void ChangeToIdleState() override;
	void ChangeToActionState() override;

	void ResolveCollision(GameEntities* ar_Entity) override;
	void ResolveCollision(SpaceShip *ar_Ship) override;
	void ResolveCollision(ShipBullet *ar_Bullet) override;
};

