#include "Enemies.h"
#include "GameEntitiessingleton.h"

Enemies::Enemies(std::string ar_FileName): GameEntities(ar_FileName), pr_CurrentState(nullptr)
{
	SetPosition(500,500);
	GameEntitiesSingleton::GetInstance()->AddEnemy(this);
}

Enemies::~Enemies()
{
	delete pr_CurrentState;
}

float Enemies::GetActionRange() const
{
	return pr_ActionRange;
}


void Enemies::SetState(EnemyState* ar_NewState)
{
	pr_CurrentState = ar_NewState;
}
