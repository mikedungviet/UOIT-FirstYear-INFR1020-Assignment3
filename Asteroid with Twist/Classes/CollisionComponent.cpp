#include "CollisionComponent.h"

/*
 * @brief Constructor for CollisionComponent class.
 * This set the default radius to 0 and position to 0
 */
CollisionComponent::CollisionComponent()
{
	pr_Position = new Vector2;
	pr_Radius = new float;
	*pr_Radius = 0;
}

/*
 * @brief Destructor for CollisionComponent class.
 * This delete any dynamic allocated variables
 */
CollisionComponent::~CollisionComponent()
{
	delete pr_Radius;
	delete pr_Position;
}

/*
 *@brief This function returns the position vector. This can
 *be modified
 *
 *@return The position vector as Vector2
 */
Vector2* CollisionComponent::GetPosition()
{
	return pr_Position;
}

/*
 *@brief This function returns the position vector. This cannot
 *be modified
 *
 **@return The position vector as Vector2
 */
Vector2* CollisionComponent::GetPosition() const
{
	return pr_Position;
}

/*
 * @brief This function returns the radius of the object
 * 
 * @return The radius of the object as float 
 */
float* CollisionComponent::GetRadius()
{
	return pr_Radius;
}

/*
 * @brief This function sets the radius for the object
 * 
 * @param ar_NewRadius The new radius for the object
 */
void CollisionComponent::SetRadius(const float& ar_NewRadius)
{
	*pr_Radius = ar_NewRadius;
}

/*
 * @brief This function updates the new position of the Sprite
 * using the velocity from the MovementComponent and deltaTime 
 * of the update
 * 
 * @param ar_DeltaTime The time difference between the current frame
 * and the last frame
 * 
 * @param ar_SpriteVelocity The current Velocity of the Sprite
 */
void CollisionComponent::Update(const float& ar_DeltaTime, const Vector2* ar_SpriteVelocity)
{
	*pr_Position += (*ar_SpriteVelocity) * ar_DeltaTime;
}