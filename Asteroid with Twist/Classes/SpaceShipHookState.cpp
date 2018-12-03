#include "SpaceShipHookState.h"
#include "SpaceShip.h"
#include "SpaceShipNormalState.h"
#include "GameEntitiesSingleton.h"


Vector2 SpaceShipHookState::FindPerpendicularVectorCounterClockWise(Vector2 &ar_Vector2)
{
	auto lo_TempVector = ar_Vector2;
	auto lo_Temp = lo_TempVector.x;
	lo_TempVector.x = -lo_TempVector.y;
	lo_TempVector.y = lo_Temp;
	return lo_TempVector;
}

SpaceShipHookState::SpaceShipHookState()
{
	const auto lo_ShipPosition = *GameEntitiesSingleton::GetInstance()->GetSpaceShip()->
		GetCollisionComponent()->GetPosition(); //Position of the Ship

	const auto lo_AsteroidPosition = *GameEntitiesSingleton::GetInstance()->
		GetAsteroidPosition(); //Position of the hit asteroid

		/*Calculate the distance between the ship and the asteroid
		 *This will be the radius */
	pr_DistanceToAsteroid = std::pow(Vector2::CalculateDistanceBetweenTwoVectors(
		lo_ShipPosition, lo_AsteroidPosition), 2);

	/*Find the direction of the centripetal force*/

	//Update the ship direction vector so that it is perpendicular
}


SpaceShipHookState::~SpaceShipHookState()
{
}

/*
 *
 */
void SpaceShipHookState::Update(const float& ar_DeltaTime, SpaceShip* ar_Entity)
{
	const auto lo_AsteroidPosition = *GameEntitiesSingleton::GetInstance()->
		GetAsteroidPosition(); //Position of the hit asteroid

	//Update the centripetal acceleration direction
	pr_CentripetalDirection = Vector2::CalculateNormalizedVector(lo_AsteroidPosition-
		(*ar_Entity->GetCollisionComponent()->GetPosition()));

	//Update the spaceship direction vector
	auto lo_OtherVector = FindPerpendicularVectorCounterClockWise(pr_CentripetalDirection);

	//Find the new acceleration direction
	Vector2 lo_MovingDirection = pr_CentripetalDirection+lo_OtherVector;
	ar_Entity->ChangeEntityDirection(lo_OtherVector);

	//Find the centripetal acceleration
	auto lo_CentripetalAcceleration = std::pow(ar_Entity->GetMovementComponent()->GetVelocity()->CalculateLength(), 2)/ pr_DistanceToAsteroid;
	float lo_ShipAccelerationMagnitude = *ar_Entity->GetMovementComponent()->GetAppliedForce();
	float lo_NetAcceleration = std::sqrt(std::pow(lo_CentripetalAcceleration, 2) + std::pow(lo_ShipAccelerationMagnitude, 2));

	//Kinematic and Dynamic equations update
	Vector2 lo_MovingForce = Vector2(lo_NetAcceleration * lo_MovingDirection.x, lo_NetAcceleration * lo_MovingDirection.y);
	ar_Entity->GetMovementComponent()->SetAcceleration(lo_MovingForce);

	*ar_Entity->GetMovementComponent()->GetVelocity() += *ar_Entity->GetMovementComponent()->GetAcceleration()*ar_DeltaTime;

	ar_Entity->GetCollisionComponent()->Update(ar_DeltaTime, ar_Entity->GetMovementComponent()->GetVelocity());
	ar_Entity->CheckPositionOutOfMap();

	//Update Sprite Location
	ar_Entity->GetSprite()->setPosition(ar_Entity->GetCollisionComponent()->GetPosition()->x,
		ar_Entity->GetCollisionComponent()->GetPosition()->y);

}

/*
 *
 */
void SpaceShipHookState::ChangeToNormalState(SpaceShip* ar_Entity) const
{
	ar_Entity->SetState(new SpaceShipNormalState);
	delete this;
}

/*
 * @brief
 */
void SpaceShipHookState::ApplyForceForward(SpaceShip* ar_Ship)
{
	ar_Ship->GetMovementComponent()->SetAppliedForce(200);
}
