#include "KamikazeEnemy.h"
#include "EnemyMovingState.h"

unsigned int KamikazeEnemy::count = 0;

KamikazeEnemy::KamikazeEnemy(): Enemies("EnemyShootingShip.png")
{
	SetPosition(rand() % 10000 + 500, rand() % 10000 + 500);
	pr_CurrentState = new EnemyMovingState(this);
	pr_ActionRange = 200;
	count++;
}


KamikazeEnemy::~KamikazeEnemy()
{
	count--;
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
