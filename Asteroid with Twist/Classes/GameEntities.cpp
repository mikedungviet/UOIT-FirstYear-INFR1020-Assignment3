#include "GameEntities.h"

/*
 * @brief Constructor for GameEntities class.
 */
GameEntities::GameEntities(const std::string& ar_FileName, const float& ar_FrictionCoefficient)
{
	//Initialize member variables
	pr_ObjectGraphic = cocos2d::Sprite::create(ar_FileName);
	pr_Collision = new CollisionComponent;
	pr_Movement = new MovementComponent(ar_FrictionCoefficient);
	pr_Theta = new float;

	//Set values to default
	pr_Collision->SetRadius(CalculateSpriteRadius());
	*pr_Theta = 0;
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
	delete pr_Theta;
}

/*
 *@brief This function returns the memory address
 *of the sprite
 *
 *@return Returns the address of the sprite of
 *the game entity
 */
cocos2d::Sprite* GameEntities::GetSprite() const
{
	return pr_ObjectGraphic;
}

/*
 *@brief This function returns the memory address of the
 *collision component
 *
 *@return Returns the address of the collision component of
 *the game entity
 */
CollisionComponent* GameEntities::GetCollisionComponent() const
{
	return pr_Collision;
}

/*
 *@brief This function returns the memory address of the
 *movement component
 *
 *@return Returns the address of the movement component of
 *the game entity
 */
MovementComponent* GameEntities::GetMovementComponent() const
{
	return pr_Movement;
}

/*
 * @brief This function returns the address of the angle
 *
 * @return Return the address of the angle
 */
float* GameEntities::GetAngle() const
{
	return pr_Theta;
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
 * @brief This function updates all the kinematic physics part
 * of the sprite
 *
 * @param ar_DeltaTime The time difference between the current
 * frame and last frame
 */
void GameEntities::Update(const float& ar_DeltaTime)
{
	pr_Movement->Update(ar_DeltaTime); //Update the kinematics equations
	
	//Update the position of the sprite
	pr_Collision->Update(ar_DeltaTime, pr_Movement->GetVelocity());
	CheckPositionOutOfMap();

	//Update the sprite position to draw on screen
	pr_ObjectGraphic->setPosition((*pr_Collision->GetPosition()).x,
	                              (*pr_Collision->GetPosition()).y);
}

/*
 * @brief Check if the object goes out of the map size
 */
void GameEntities::CheckPositionOutOfMap() const
{
	const auto lo_Size = pr_ObjectGraphic->getBoundingBox().size;
	if (pr_Collision->GetPosition()->x + lo_Size.width > 10000)
		pr_Collision->GetPosition()->x = 0 + lo_Size.width;
	if (pr_Collision->GetPosition()->x - lo_Size.width < 0)
		pr_Collision->GetPosition()->x = 10000 - lo_Size.width;
	if (pr_Collision->GetPosition()->y + lo_Size.height > 10000)
		pr_Collision->GetPosition()->y = 0 + lo_Size.height;
	if (pr_Collision->GetPosition()->y - lo_Size.height < 0)
		pr_Collision->GetPosition()->y = 10000 - lo_Size.height;
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

/*
 *@brief Add the entity's angle with a float
 *
 *@param ar_Angle the float to add the angle to
 */
void GameEntities::AddAngle(const float& ar_Angle) const
{
	*pr_Theta += ar_Angle;
	if (*pr_Theta < 0)
		*pr_Theta += 360;
	else if (*pr_Theta > 360)
		*pr_Theta -= 360;

	//pr_ObjectGraphic->runAction(cocos2d::RotateBy::create(0.0f, ar_Angle));
	pr_Movement->UpdateDirection(*pr_Theta);
	pr_ObjectGraphic->setRotation(*pr_Theta);
}

void GameEntities::CheckPositionOutOfMap(GameEntities* ar_GameEntities)
{
	const auto lo_Size = ar_GameEntities->GetSprite()->getBoundingBox().size;
	if (ar_GameEntities->GetCollisionComponent()->GetPosition()->x + lo_Size.width > 10000)
		ar_GameEntities->GetCollisionComponent()->GetPosition()->x = 0 + lo_Size.width;
	if (ar_GameEntities->GetCollisionComponent()->GetPosition()->x - lo_Size.width < 0)
		ar_GameEntities->GetCollisionComponent()->GetPosition()->x = 10000 - lo_Size.width;
	if (ar_GameEntities->GetCollisionComponent()->GetPosition()->y + lo_Size.height > 10000)
		ar_GameEntities->GetCollisionComponent()->GetPosition()->y = 0 + lo_Size.height;
	if (ar_GameEntities->GetCollisionComponent()->GetPosition()->y - lo_Size.height < 0)
		ar_GameEntities->GetCollisionComponent()->GetPosition()->y = 10000 - lo_Size.height;
}
