#pragma once
#include "Enemies.h"


class Boss :
	public Enemies
{
public:
	Boss();
	~Boss();

	//Updating Functions
	void Update(const float& ar_DeltaTime) override;
	void ChangeToIdleState() override;
	void ChangeToActionState() override;


	//Resolving Collision
	void ResolveCollision(GameEntities* ar_Entity) override;
};

