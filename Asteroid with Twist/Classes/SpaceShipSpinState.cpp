#include "SpaceShipSpinState.h"
#include "SpaceShip.h"
#include "SpaceShipNormalState.h"

/*
 *
 */
SpaceShipSpinState::SpaceShipSpinState():pr_TotalTime{5}
{
	
}

/*
 * @brief The Destructor for the SpaceShipSpinState.
 * Delete any dynamic allocated variables
 */
SpaceShipSpinState::~SpaceShipSpinState(){/*Empty*/}

/*
 * @brief This state spins the ship around for 5 seconds
 */
void SpaceShipSpinState::Update(const float& ar_DeltaTime, SpaceShip* ar_Entity)
{
	pr_TotalTime -= ar_DeltaTime;
	ar_Entity->GetMovementComponent()->SetVelocity(0, 0);
	ar_Entity->AddAngle(20.f);
	if (pr_TotalTime <= 0)
		ChangeToNormalState(ar_Entity);
}

/*
 *@brief This function changes the SpaceShip state from spinning to normal
 *
 *@param The memory address of the SpaceShip class
 */
void SpaceShipSpinState::ChangeToNormalState(SpaceShip* ar_Entity) const
{
	ar_Entity->SetState(new SpaceShipNormalState);
	delete this;
}



