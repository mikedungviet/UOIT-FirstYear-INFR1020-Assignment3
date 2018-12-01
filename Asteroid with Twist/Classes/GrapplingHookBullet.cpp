#include "GrapplingHookBullet.h"
#include "SpaceShip.h"

/*
 * @brief This Constructor creates a bullet when called. When a bullet is created, it has the ship's
 * current position and velocity
 */
GrapplingHookBullet::GrapplingHookBullet(const SpaceShip * ar_Ship): GameEntities("EnemyBullet.png"), pr_LifeTime(3.f)
{
	SetPosition(Vector2(ar_Ship->GetCollisionComponent()->GetPosition()->x,
		ar_Ship->GetCollisionComponent()->GetPosition()->y));
	pr_Movement->SetVelocity(*ar_Ship->GetMovementComponent()->GetVelocity());
	pr_Movement->SetDirectionVector(*ar_Ship->GetMovementComponent()->GetDirectionVector());
	pr_Movement->SetAppliedForce(1500);
	GameEntitiesSingleton::GetInstance()->AddEntity(this);
}


GrapplingHookBullet::~GrapplingHookBullet()
{
}

/*
 *@brief This function updates the position of the Grappling Hook
 *Bullet
 *
 *@param ar_DeltaTime The time difference between the current frame vs
 *the last frame
 */
void GrapplingHookBullet::Update(const float& ar_DeltaTime)
{
	GameEntities::Update(ar_DeltaTime);
	pr_LifeTime -= ar_DeltaTime;
	if (pr_LifeTime < 0) {
		GameEntitiesSingleton::GetInstance()->DeleteEntity(this);
		GameEntitiesSingleton::GetInstance()->GetSpaceShip()->ChangeToNormalMode();
	}
}

void GrapplingHookBullet::ResolveCollision(GameEntities* ar_Entity)
{
	ar_Entity->ResolveCollision(this);
}

/*
 *
 */
void GrapplingHookBullet::ResolveCollision(SmallAsteroid* ar_SmallAsteroid)
{
	pr_Lives -= 1;
	GameEntitiesSingleton::GetInstance()->GetSpaceShip()->ChangeToNormalMode();
}
