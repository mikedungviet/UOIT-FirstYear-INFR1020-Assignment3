#include "ShipBullet.h"
#include "SpaceShip.h"
#include "GameEntitiesSingleton.h"

/*
 * @brief Constructor for ShipBullet class
 */
ShipBullet::ShipBullet(const SpaceShip *ar_Ship): GameEntities("Bullet.png"), pr_LifeTime{1.5f}
{
	const auto lo_MaxX = cocos2d::Director::getInstance()->getRunningScene()->getBoundingBox().getMaxX();
	const auto lo_MaxY = cocos2d::Director::getInstance()->getRunningScene()->getBoundingBox().getMaxY();
	SetPosition(Vector2(lo_MaxX/2, lo_MaxY/2));
	//pr_Movement->SetVelocity(*ar_Ship->GetMovementComponent()->GetVelocity());
	pr_Movement->SetDirectionVector(*ar_Ship->GetMovementComponent()->GetDirectionVector());
	pr_Movement->SetAppliedForce(500);
	GameEntitiesSingleton::GetInstance()->AddEntity(this);
}

/*
 * @brief Destructor for the Ship Bullet
 */
ShipBullet::~ShipBullet(){/*Empty*/}

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

