#include "KamikazeEnemy.h"
#include "EnemyMovingState.h"


KamikazeEnemy::KamikazeEnemy(): Enemies("EnemyShootingShip.png")
{
	SetPosition(500, 500);
	pr_CurrentState = new EnemyMovingState(this);
	pr_ActionRange = 200;
}


KamikazeEnemy::~KamikazeEnemy()
{
}

void KamikazeEnemy::Update(const float& ar_DeltaTime)
{
	pr_CurrentState->Update(ar_DeltaTime);
}

void KamikazeEnemy::ChangeToIdleState()
{
	pr_CurrentState->ChangeToMovingState();
}

void KamikazeEnemy::ChangeToActionState()
{
	pr_CurrentState->ChangeToSuicideState();
}

void KamikazeEnemy::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

void KamikazeEnemy::ResolveCollision(SpaceShip* ar_Ship)
{
	pr_Lives--;
}

void KamikazeEnemy::ResolveCollision(ShipBullet* ar_Bullet)
{
	pr_Lives--;
}
