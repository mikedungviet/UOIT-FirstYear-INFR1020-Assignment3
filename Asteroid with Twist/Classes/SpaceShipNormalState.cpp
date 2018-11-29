#include "SpaceShipNormalState.h"
#include "SpaceShip.h"
#include "SpaceShipSpinState.h"


SpaceShipNormalState::SpaceShipNormalState()
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
	ar_Entity->GetMovementComponent()->Update(ar_DeltaTime);
	ar_Entity->GetCollisionComponent()->Update(ar_DeltaTime, ar_Entity->GetMovementComponent()->GetVelocity());
	ar_Entity->CheckPositionOutOfMap();
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



