#include "BlackHoles.h"
#include "BlackHolesSingleton.h"

/*
 *@brief This function calculates the force vector to apply to the entity. The magnitude is inverse proportional
 *to the distance between the entity and the black hole. The direction is from the entity to the black hole.
 *
 *@param ar_Collision The pointer to the game entity's collision component
 *@param ar_Distance The reference to the calculated distance between two objects
 *
 * @return Returns the calculated vector to be used to apply to the entity
 */
Vector2 BlackHoles::CalculateAddingForce(const CollisionComponent* ar_Collision, const float& ar_Distance) const
{
	//Calculate the direction where the force will be applied to (should be from the entity to the black hole)
	const auto lo_Direction = Vector2::CalculateNormalizedVector(*pr_Collision->GetPosition()-
		*ar_Collision->GetPosition());

	//Calculate the magnitude.
	const auto lo_Magnitude = 100000 / ar_Distance;

	return lo_Direction * lo_Magnitude;
}

/*
 * @brief This functions uses the image size and pythagorean theorem to calculate the
 * radius of the image
 *
 * @return Returns the radius as a float
 */
float BlackHoles::CalculateSpriteRadius() const
{
	const auto lo_Size = pr_Sprite->getBoundingBox().size;
	return std::sqrt(std::pow(lo_Size.width / 2, 2) + std::pow(lo_Size.height / 2, 2));
}

/*
 * @brief This is the constructor for BlackHoles. It creates a new Collision Component, Sprite
 * and it calculates the object radius based on the image size;
 */
BlackHoles::BlackHoles() : pr_AffectedDistance(750)
{
	pr_Collision = new CollisionComponent;
	pr_Sprite = cocos2d::Sprite::create("BubbleTea.png");

	pr_Collision->SetRadius(70);
	SetPosition(750, 750);
	BlackHolesSingleton::GetInstance()->AddBlackHole(this);
}

/*
 * @brief This is the Destructor for BlackHoles. It deletes any dynamic allocated variables
 */
BlackHoles::~BlackHoles()
{
	delete pr_Collision;
}

/*
 * @brief This function returns the pointer for the BlackHole's collision component
 *
 * @return Return CollisionComponent pointer
 */
CollisionComponent* BlackHoles::GetCollision() const
{
	return pr_Collision;
}

/*
 * @brief This function returns the pointer for the BlackHole's sprite
 *
 * @return Return cocos2d::Sprite pointer
 */
cocos2d::Sprite* BlackHoles::GetSprite() const
{
	return pr_Sprite;
}

/*
 * @brief This function sets the entity new position
 * (both physics and location on screen)
 *
 * @param ar_NewPosition The reference to Vector2 to set the
 * new position to
 */
void BlackHoles::SetPosition(const Vector2& ar_NewPosition) const
{
	pr_Collision->GetPosition()->x = ar_NewPosition.x;
	pr_Collision->GetPosition()->y = ar_NewPosition.y;
	pr_Sprite->setPosition(ar_NewPosition.x, ar_NewPosition.y);
}

/*
 * @brief This function sets the entity new position
 * (both physics and location on screen)
 *
 * @param ar_NewX The new X position
 * @param ar_NewY The new Y position
 */
void BlackHoles::SetPosition(const float& ar_NewX, const float& ar_NewY) const
{
	pr_Collision->GetPosition()->x = ar_NewX;
	pr_Collision->GetPosition()->y = ar_NewY;
	pr_Sprite->setPosition(ar_NewX, ar_NewY);
}

/*
 *@brief This function checks if the Game Entity position is in range. If it is not in range, do nothing. 
 *But if it does, call CalculateAddingForce and set the additional force for the ship.
 */
void BlackHoles::AddAdditionalForceToEntity(GameEntities* ar_Entity)
{
	const auto lo_DistanceBetweenEntityAndHole =
		Vector2::CalculateDistanceBetweenTwoVectors(*ar_Entity->GetCollisionComponent()->GetPosition(),
		                                            *pr_Collision->GetPosition());

	//Check if the force apply
	if (lo_DistanceBetweenEntityAndHole > pr_AffectedDistance)
		return;

	ar_Entity->GetMovementComponent()->AddOtherForce(CalculateAddingForce(ar_Entity->GetCollisionComponent(),
	                                                                      lo_DistanceBetweenEntityAndHole));
}
