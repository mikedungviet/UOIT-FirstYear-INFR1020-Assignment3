#include "EnemyShootingState.h"
#include "Enemies.h"
#include "EnemyMovingState.h"
#include "EnemyBullet.h"
#include "GameEntitiesSingleton.h"
#include "SpaceShip.h"
#include "EnemyStandStillState.h"

EnemyShootingState::EnemyShootingState(Enemies *ar_Enemy, const int &ar_ShootSpeed ) : pr_BulletSpawningCounter(0)
{
	pr_SpaceShipCollisionComponent = GameEntitiesSingleton::GetInstance()->GetSpaceShip()->GetCollisionComponent();
	pr_Enemy = ar_Enemy;
	pr_Enemy->GetMovementComponent()->SetVelocity(0, 0);
	pr_ShotSpeed = ar_ShootSpeed;
}


EnemyShootingState::~EnemyShootingState()
{
}

void EnemyShootingState::Update(const float& ar_DeltaTime)
{
	//Find the direction of from this object to the space ship
	auto lo_DirectionToShip = Vector2::CalculateNormalizedVector(Vector2(pr_SpaceShipCollisionComponent->GetPosition()->x - pr_Enemy->GetCollisionComponent()->GetPosition()->x,
		pr_SpaceShipCollisionComponent->GetPosition()->y - pr_Enemy->GetCollisionComponent()->GetPosition()->y));
	pr_Enemy->ChangeEntityDirection(lo_DirectionToShip);

	//Some sort of randomness/ counter to spawn bullets
	pr_BulletSpawningCounter++;
	if (pr_BulletSpawningCounter <= pr_ShotSpeed) {
		//Create a bullet
		auto lo_TempEnemyBullet = new EnemyBullet;
		lo_TempEnemyBullet->SetPosition(*pr_Enemy->GetCollisionComponent()->GetPosition());
		//Set a force of this bullet
		lo_TempEnemyBullet->GetMovementComponent()->SetDirectionVector(lo_DirectionToShip);

		pr_BulletSpawningCounter = 0;
	}
}

void EnemyShootingState::ChangeToMovingState()
{
	pr_Enemy->SetState(new EnemyMovingState(pr_Enemy));
	delete this;
}

void EnemyShootingState::ChangeToStandStillState()
{
	pr_Enemy->SetState(new EnemyStandStillState(pr_Enemy));
	delete this;
}
