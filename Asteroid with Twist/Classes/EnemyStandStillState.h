#pragma once
#include "EnemyState.h"
class EnemyStandStillState :
	public EnemyState
{
public:
	EnemyStandStillState(Enemies *ar_Enemy);
	~EnemyStandStillState();

	void Update(const float& ar_DeltaTime) override;

	void ChangeToShootingState() override;
};

