#include "SpaceShip.h"


SpaceShip::SpaceShip(): GameEntities("Ship.png")
{
}


SpaceShip::~SpaceShip()
{
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
	GameEntities::Update(ar_DeltaTime);
}
