#pragma once

class SpaceShip;
class Enemies;

class EnemyState
{
protected:
	Enemies *pr_Enemy;
public:
	~EnemyState();

	virtual void Update(const float &ar_DeltaTime) = 0;

	//Changing State
	virtual void ChangeToMovingState(){}
	virtual void ChangeToShootingState(){}
	
};

