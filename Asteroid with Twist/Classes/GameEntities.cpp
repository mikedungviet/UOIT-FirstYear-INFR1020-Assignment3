#include "GameEntities.h"

/*
 * @brief Constructor for GameEntities class.
 */
GameEntities::GameEntities(const std::string& ar_FileName)
{
	//Initialize member variables
	pr_ObjectGraphic = cocos2d::Sprite::create(ar_FileName);
	pr_Collision = new CollisionComponent;
	pr_Movement = new MovementComponent;

	//Set values to default
	pr_Collision->SetRadius(CalculateSpriteRadius());
}

/*
 * @brief Destructor for GameEntities class.
 * Delete any dynamic allocated variables
 */
GameEntities::~GameEntities()
{
	delete pr_Collision;
	delete pr_Movement;
	delete pr_ObjectGraphic;
}

/*
 *
 */
cocos2d::Sprite* GameEntities::GetSprite()
{
	return pr_ObjectGraphic;
}

/*
 *
 */
CollisionComponent* GameEntities::GetCollisionComponent()
{
	return pr_Collision;
}

/*
 *
 */
MovementComponent* GameEntities::GetMovementComponent()
{
	return pr_Movement;
}


/*
 * @brief This function sets the entity new position
 * (both physics and location on screen)
 *
 * @param ar_NewPosition The reference to Vector2 to set the
 * new position to
 */
void GameEntities::SetPosition(const Vector2& ar_NewPosition) const
{
	(*pr_Collision->GetPosition()).x = ar_NewPosition.x;
	(*pr_Collision->GetPosition()).y = ar_NewPosition.y;
	pr_ObjectGraphic->setPosition(ar_NewPosition.x, ar_NewPosition.y);
}

/*
 * @brief This function sets the entity new position
 * (both physics and location on screen)
 *
 * @param ar_NewX The new X position
 * @param ar_NewY The new Y position
 */
void GameEntities::SetPosition(const float& ar_NewX, const float& ar_NewY) const
{
	(*pr_Collision->GetPosition()).x = ar_NewX;
	(*pr_Collision->GetPosition()).y = ar_NewY;
	pr_ObjectGraphic->setPosition(ar_NewX, ar_NewY);
}


/*
 * @brief This function calculate the radius base
 * on the Sprite size
 */
float GameEntities::CalculateSpriteRadius() const
{
	const auto lo_Size = pr_ObjectGraphic->getBoundingBox().size;
	return std::sqrt(std::pow(lo_Size.width / 2, 2) +
		std::pow(lo_Size.height / 2, 2));
}
