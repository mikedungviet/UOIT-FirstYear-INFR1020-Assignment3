#include "SpaceShip.h"
#include "SpaceShipNormalState.h"


SpaceShip::SpaceShip(): GameEntities("Ship.png")
{
	pr_CurrentState = new SpaceShipNormalState;
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
	pr_CurrentState->Update(ar_DeltaTime, pr_Movement, pr_Collision);
	CheckPositionOutOfMap();
	//Update the sprite position to draw on screen
	pr_ObjectGraphic->setPosition((*pr_Collision->GetPosition()).x,
		(*pr_Collision->GetPosition()).y);
}
