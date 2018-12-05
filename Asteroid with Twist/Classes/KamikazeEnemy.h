#pragma once
#include "Enemies.h"

class KamikazeEnemy :
	public Enemies
{
public:
	KamikazeEnemy();
	~KamikazeEnemy();

	void Update(const float& ar_DeltaTime) override;

	void ChangeToIdleState() override;
	void ChangeToActionState() override;

	void ResolveCollision(GameEntities* ar_Entity) override;
};

