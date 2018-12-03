#include "SpaceShipNormalState.h"
#include "SpaceShip.h"
#include "SpaceShipSpinState.h"
#include "SpaceShipHookState.h"

/*
 * @brief
 */
SpaceShipNormalState::SpaceShipNormalState(): pr_Friction(100)
{
}


SpaceShipNormalState::~SpaceShipNormalState()
{
}

/*
 * @brief This function uses kinematic and dynamic physic equations to update the game entity
 * 
 * @param ar_DeltaTime The time difference between the current frame vs the last frame
 * @param ar_Entities The memory address of the updating SpaceShip
 */
void SpaceShipNormalState::Update(const float& ar_DeltaTime, SpaceShip* ar_Entity)
{
	Vector2 lo_NetForceVector;

	const Vector2 lo_AppliedForceVector
	(*ar_Entity->GetMovementComponent()->GetAppliedForce() * ar_Entity->GetForceDirection()->x,
	 *ar_Entity->GetMovementComponent()->GetAppliedForce() * ar_Entity->GetForceDirection()->y);

	//If the object is moving, apply friction to the net force
	if (ar_Entity->GetMovementComponent()->GetVelocity()->CalculateLength() != 0)
	{
		const Vector2 lo_VelocityDirection(ar_Entity->GetMovementComponent()->GetVelocity()->NormalizeVector());
		const Vector2 lo_FrictionVector(lo_VelocityDirection * -pr_Friction);
		lo_NetForceVector = lo_AppliedForceVector + lo_FrictionVector;
	}
		//If the object is not moving, DO NOT apply friction to net force
	else
		lo_NetForceVector = lo_AppliedForceVector;

	//Update kinematic equations
	ar_Entity->GetMovementComponent()->SetAcceleration((lo_NetForceVector));
	*ar_Entity->GetMovementComponent()->GetVelocity() += *ar_Entity->GetMovementComponent()->GetAcceleration() * ar_DeltaTime;

	//Update the position
	ar_Entity->GetCollisionComponent()->Update(ar_DeltaTime, ar_Entity->GetMovementComponent()->GetVelocity());
	ar_Entity->CheckPositionOutOfMap();

	//Update Sprite Location
	ar_Entity->GetSprite()->setPosition(ar_Entity->GetCollisionComponent()->GetPosition()->x,
	                                    ar_Entity->GetCollisionComponent()->GetPosition()->y);
}

/*
 *@brief This function changes the SpaceShip state from normal to spinning
 *
 *@param ar_Entity The memory address of the updating spaceship
 */
void SpaceShipNormalState::ChangeToSpinState(SpaceShip* ar_Entity) const
{
	ar_Entity->SetState(new SpaceShipSpinState);
	delete this;
}

/*
 *@brief This function changes the SpaceShip state from normal to hook
 *
 *@param ar_Ship The pointer of the updating spaceship
 */
void SpaceShipNormalState::ChangeToHookState(SpaceShip* ar_Ship) const
{
	ar_Ship->SetState(new SpaceShipHookState);
	delete this;
}

/*
 * @brief This function apply force at the direction of the force
 * of the ship
 */
void SpaceShipNormalState::ApplyForceForward(SpaceShip* ar_Ship)
{
	ar_Ship->GetMovementComponent()->SetAppliedForce(ar_Ship->GetSpeed());
	*ar_Ship->GetForceDirection() = *ar_Ship->GetMovementComponent()->GetDirectionVector();
}

/*
 *@brief This function apply force at the negative direction
 *of the ship
 */
void SpaceShipNormalState::ApplyForceBackward(SpaceShip* ar_Ship)
{
	ar_Ship->GetMovementComponent()->SetAppliedForce(-ar_Ship->GetSpeed());
	*ar_Ship->GetForceDirection() = *ar_Ship->GetMovementComponent()->GetDirectionVector();
}

/*
 *@brief This function find the normal of the direction, and apply force
 *at that direction.
 *
 *The normal vector is for left direction has a opposite sign for y
 */
void SpaceShipNormalState::ApplyForceLeft(SpaceShip* ar_Ship)
{
	//Finding the normal vector
	auto lo_TempVector = *ar_Ship->GetMovementComponent()->GetDirectionVector();
	const auto lo_TempFloat = lo_TempVector.x;
	lo_TempVector.x = lo_TempVector.y*-1; //Set the y to negative
	lo_TempVector.y = lo_TempFloat;

	ar_Ship->GetMovementComponent()->SetAppliedForce(-ar_Ship->GetSpeed());
	*ar_Ship->GetForceDirection() = lo_TempVector;
}

/*
 *@brief This function find the normal of the direction, and apply force
 *at that direction.
 *
 *The normal vector is for left direction has a opposite sign for x
 */
void SpaceShipNormalState::ApplyForceRight(SpaceShip* ar_Ship)
{
	//Finding the normal vector
	auto lo_TempVector = *ar_Ship->GetMovementComponent()->GetDirectionVector();
	const auto lo_TempFloat = lo_TempVector.x;
	lo_TempVector.x = lo_TempVector.y;
	lo_TempVector.y = lo_TempFloat * -1; //Set the y to negative

	ar_Ship->GetMovementComponent()->SetAppliedForce(-ar_Ship->GetSpeed());
	*ar_Ship->GetForceDirection() = lo_TempVector;
}

/*
 * @brief This function rotates the sprite by a degree to the right
 */
void SpaceShipNormalState::RotateLeft(SpaceShip* ar_Ship)
{
	ar_Ship->AddAngle(-20);
}

/*
 *@brief This function rotates the sprite by a degree to the right
 */
void SpaceShipNormalState::RotateRight(SpaceShip* ar_Ship)
{
	ar_Ship->AddAngle(20);
}






