#include "SpaceShipNormalState.h"
#include "SpaceShip.h"
#include "SpaceShipSpinState.h"

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
void SpaceShipNormalState::Update(const float& ar_DeltaTime, SpaceShip* ar_Entity) const
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



