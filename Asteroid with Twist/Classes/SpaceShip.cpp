#include "SpaceShip.h"
#include "SpaceShipNormalState.h"
#include "SpaceShipSpinState.h"


SpaceShip::SpaceShip(): GameEntities("Ship.png", 50)
{
	pr_CurrentState = new SpaceShipNormalState;
}


SpaceShip::~SpaceShip()
{
	delete pr_CurrentState;
}

/*
 *@brief This function changes the SpaceShip State to a new one
 *
 *@param The new SpaceShip State to set to
 */
void SpaceShip::SetState(SpaceShipState* ar_NewState)
{
	pr_CurrentState = ar_NewState;
}

/*
 * @brief This function override the Update function in
 * GameEntities. It updates all the kinematic physics part
 * of the sprite
 * 
 * @param ar_DeltaTime The time difference between the current
 * frame and the last frame
 */
void SpaceShip::Update(const float& ar_DeltaTime)
{
	pr_CurrentState->Update(ar_DeltaTime, this);
}

/*
 * @brief This function sets the current state to normal state
 */
void SpaceShip::ChangeToNormalState()
{
	pr_CurrentState->ChangeToNormalState(this);
}

/*
 * @brief This function sets the current state to spinning state
 */
void SpaceShip::ChangeToSpinState()
{
	pr_CurrentState->ChangeToSpinState(this);
}
