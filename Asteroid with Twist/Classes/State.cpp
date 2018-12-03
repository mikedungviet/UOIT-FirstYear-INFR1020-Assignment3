#include "State.h"


SpaceShipState::~SpaceShipState()
{
}

/*
 * @brief This function is called when the spaceship is in normal state
 * but call to change to normal state. It does nothing.
 */
void SpaceShipState::ChangeToNormalState(SpaceShip* ar_Entity) const
{
	return;
}

/*
 *@brief This function is called when the spaceship is in spinning state
 *but call to change to spinning state. It does nothing
 */
void SpaceShipState::ChangeToSpinState(SpaceShip* ar_Entity) const
{
	return;
}

/*
 *@brief This function is called when the spaceship is in hook state
 *but call to change to spinning state. It does nothing
 */
void SpaceShipState::ChangeToHookState(SpaceShip* ar_Ship) const
{
	return;
}
