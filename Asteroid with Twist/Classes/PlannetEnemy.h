#pragma once
#include "Enemies.h"
class PlannetEnemy :
	public Enemies
{
public:
	PlannetEnemy();
	~PlannetEnemy();

	void Update(const float& ar_DeltaTime) override;

	void ChangeToIdleState() override;
	void ChangeToActionState() override;

	void ResolveCollision(GameEntities* ar_Entity) override;

};

