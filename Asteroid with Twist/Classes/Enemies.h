#pragma once
#include "GameEntities.h"
#include "EnemyState.h"

class Enemies :
	public GameEntities
{
protected:
	EnemyState *pr_CurrentState;
	Enemies(std::string ar_FileName);
public:
	~Enemies();
	void SetState(EnemyState *ar_NewState);

	virtual void ChangeToIdleState() = 0;
	virtual void ChangeToActionState() = 0;
	//virtual void ChangeToSpinState();
};

