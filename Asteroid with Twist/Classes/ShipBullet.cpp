#include "ShipBullet.h"
#include "SpaceShip.h"
#include "GameEntitiesSingleton.h"

/*
 * @brief Constructor for ShipBullet class. When a bullet is created, it has the ship's
 * current position and velocity
 * 
 * @param ar_Ship The SpaceShip pointer.
 */
ShipBullet::ShipBullet(const SpaceShip* ar_Ship): GameEntities("ShipBullet.png"), pr_LifeTime{2.f}
{
	SetPosition(Vector2(ar_Ship->GetCollisionComponent()->GetPosition()->x,
	                    ar_Ship->GetCollisionComponent()->GetPosition()->y));
	pr_Movement->SetVelocity(*ar_Ship->GetMovementComponent()->GetVelocity());
	pr_Movement->SetDirectionVector(*ar_Ship->GetMovementComponent()->GetDirectionVector());
	pr_Movement->SetAppliedForce(1000);
	GameEntitiesSingleton::GetInstance()->AddEntity(this);
}

/*
 * @brief Destructor for the Ship Bullet
 */
ShipBullet::~ShipBullet()
{/*Empty*/}

/*
 *@brief 
 */
void ShipBullet::Update(const float& ar_DeltaTime)
{
	GameEntities::Update(ar_DeltaTime);
	pr_LifeTime -= ar_DeltaTime;
	if (pr_LifeTime <= 0)
		GameEntitiesSingleton::GetInstance()->DeleteEntity(this);
}

