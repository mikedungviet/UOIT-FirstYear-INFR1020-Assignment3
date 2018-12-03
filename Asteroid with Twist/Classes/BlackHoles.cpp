#include "BlackHoles.h"
#include "BlackHolesSingleton.h"

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
BlackHoles::BlackHoles(): pr_AffectedDistance(750)
{
	pr_Collision = new CollisionComponent;
	pr_Sprite = cocos2d::Sprite::create("BubbleTea.png");

	pr_Collision->SetRadius(CalculateSpriteRadius());
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
