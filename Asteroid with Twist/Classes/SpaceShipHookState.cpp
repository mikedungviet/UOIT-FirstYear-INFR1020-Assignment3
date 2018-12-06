#include "SpaceShipHookState.h"
#include "SpaceShip.h"
#include "SpaceShipNormalState.h"
#include "GameEntitiesSingleton.h"


Vector2 SpaceShipHookState::FindPerpendicularVectorCounterClockWise(Vector2& ar_Vector2)
{
	auto lo_TempVector = ar_Vector2;
	auto lo_Temp = lo_TempVector.x;
	lo_TempVector.x = lo_TempVector.y;
	lo_TempVector.y = -lo_Temp;
	return lo_TempVector;
}

SpaceShipHookState::SpaceShipHookState():pr_Friction(100)
{
	const auto lo_ShipPosition = *GameEntitiesSingleton::GetInstance()->GetSpaceShip()->
	                                                                    GetCollisionComponent()->GetPosition();
	//Position of the Ship

	const auto lo_AsteroidPosition = *GameEntitiesSingleton::GetInstance()->
		GetAsteroidPosition(); //Position of the hit asteroid

	/*Calculate the distance between the ship and the asteroid
	 *This will be the radius */
	pr_DistanceToAsteroid = Vector2::CalculateDistanceBetweenTwoVectors(lo_ShipPosition, lo_AsteroidPosition);

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
	//Position of the hit asteroid
	const auto lo_AsteroidPosition = *GameEntitiesSingleton::GetInstance()->GetAsteroidPosition();

	//Update the centripetal acceleration acceleration
	pr_CentripetalDirection = Vector2::CalculateNormalizedVector(lo_AsteroidPosition -
																(*ar_Entity->GetCollisionComponent()->GetPosition()));

	auto lo_CentripetalForce = pr_CentripetalDirection
							   * std::pow(ar_Entity->GetMovementComponent()->GetVelocity()->CalculateLength(), 2)
							   * (1 / pr_DistanceToAsteroid);

	//Update the spaceship acceleration tangent
	auto lo_TangentDirection = FindPerpendicularVectorCounterClockWise(pr_CentripetalDirection);
	float lo_ShipAccelerationMagnitude = *ar_Entity->GetMovementComponent()->GetAppliedForce();
	auto lo_ForceTangent = lo_TangentDirection * lo_ShipAccelerationMagnitude;
	ar_Entity->ChangeEntityDirection(lo_TangentDirection);

	//Kinematic and Dynamic equations update
	Vector2 lo_MovingForce = lo_ForceTangent + lo_CentripetalForce;

	//If the ship is moving, add friction opposite to the velocity
	if (ar_Entity->GetMovementComponent()->GetVelocity()->CalculateLength() > 0) {
		const Vector2 lo_VelocityDirection(ar_Entity->GetMovementComponent()->GetVelocity()->NormalizeVector());
		const Vector2 lo_FrictionVector(lo_VelocityDirection * -pr_Friction);
		lo_MovingForce += lo_FrictionVector;
	}

	//Update the physics normally
	ar_Entity->GetMovementComponent()->SetAcceleration(lo_MovingForce);
	*ar_Entity->GetMovementComponent()->GetVelocity() += *ar_Entity->GetMovementComponent()->GetAcceleration() *
		ar_DeltaTime;
	ar_Entity->GetCollisionComponent()->Update(ar_DeltaTime, ar_Entity->GetMovementComponent()->GetVelocity());

	if(ar_Entity->GetCollisionComponent()->GetPosition()->x < 0 || ar_Entity->GetCollisionComponent()->GetPosition()->x > 10000)
	{
		ChangeToNormalState(ar_Entity);
	}

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

void SpaceShipHookState::ApplyForceBackward(SpaceShip* ar_Ship)
{
	ChangeToNormalState(ar_Ship);
}

