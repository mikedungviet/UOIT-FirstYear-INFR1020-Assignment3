#include "MovementComponent.h"

/*
 * @brief Constructor for all the Vectors component. Set everything to 0
 */
MovementComponent::MovementComponent()
{
	pr_Force = new Vector2;
	pr_Acceleration = new Vector2;
	pr_Velocity = new Vector2;
}

/*
 * @brief Destructor for Movement Component. Delete any dynamic allocated
 * variables
 */
MovementComponent::~MovementComponent()
{
	delete pr_Acceleration;
	delete pr_Force;
	delete pr_Velocity;
}

/*
 *@brief This function returns the Force vector. This can
 *be modified
 *
 *@return Return the Force vector as Vector2
 */
Vector2* MovementComponent::GetForce()
{
	return pr_Force;
}

/*
 *@brief This function returns the Force vector. This cannot
 *be modified
 *
 *@return Return the Force vector as Vector2
 */
Vector2* MovementComponent::GetForce() const
{
	return pr_Force;
}

/*
 *@brief This function returns the Acceleration vector. This can
 *be modified
 *
 *@return Return the Acceleration vector as Vector2
 */
Vector2* MovementComponent::GetAcceleration()
{
	return pr_Acceleration;
}

/*
 *@brief This function returns the Acceleration vector. This cannot
 *be modified
 *
 *@return Return the Acceleration vector as Vector2
 */
Vector2* MovementComponent::GetAcceleration() const
{
	return pr_Acceleration;
}

/*
 *@brief This function returns the Velocity vector. This can
 *be modified
 *
 *@return Return the Velocity vector as Vector2
 */
Vector2* MovementComponent::GetVelocity()
{
	return pr_Velocity;
}

/*
 *@brief This function returns the Velocity vector. This cannot
 *be modified
 *
 *@return Return the Velocity vector as Vector2
 */
Vector2* MovementComponent::GetVelocity() const
{
	return pr_Velocity;
}

/*
 * @brief This function sets the Force Vector to new value
 *
 * @param ar_NewForce This is the new Vector2 to set the force to
 */
void MovementComponent::SetForce(const Vector2& ar_NewForce) const
{
	(*pr_Force).x = ar_NewForce.x;
	(*pr_Force).y = ar_NewForce.y;
}

/*
 * @brief This function sets the Force Vector to new value
 *
 * @param ar_NewX This is the new float to set the force x to
 * @param ar_NewY This is the new float to the the force y to
 */
void MovementComponent::SetForce(const float& ar_NewX, const float& ar_NewY) const
{
	(*pr_Force).x = ar_NewX;
	(*pr_Force).y = ar_NewY;
}

/*
 * @brief This function sets the Acceleration Vector to new value
 *
 * @param ar_NewForce This is the new Vector2 to set the acceleration to
 */
void MovementComponent::SetAcceleration(const Vector2& ar_NewAcceleration) const
{
	(*pr_Acceleration).x = ar_NewAcceleration.x;
	(*pr_Acceleration).y = ar_NewAcceleration.y;
}

/*
 * @brief This function sets the Acceleration Vector to new value
 *
 * @param ar_NewX This is the new float to set the acceleration x to
 * @param ar_NewY This is the new float to the the acceleration y to
 */
void MovementComponent::SetAcceleration(const float& ar_NewX, const float& ar_NewY) const
{
	(*pr_Acceleration).x = ar_NewX;
	(*pr_Acceleration).y = ar_NewY;
}

/*
 * @brief This function sets the Velocity Vector to new value
 *
 * @param ar_NewForce This is the new Vector2 to set the velocity to
 */
void MovementComponent::SetVelocity(const Vector2& ar_NewVelocity) const
{
	(*pr_Velocity).x = ar_NewVelocity.x;
	(*pr_Velocity).y = ar_NewVelocity.y;
}

/*
 * @brief This function sets the Velocity Vector to new value
 *
 * @param ar_NewX This is the new float to set the velocity x to
 * @param ar_NewY This is the new float to the the velocity y to
 */
void MovementComponent::SetVelocity(const float& ar_NewX, const float& ar_NewY) const
{
	(*pr_Velocity).x = ar_NewX;
	(*pr_Velocity).y = ar_NewY;
}


/*
 * @brief This function uses basic kinematic equations to update
 * the velocity vector
 *
 * @param deltaTime This is the time difference between the current
 * frame and last frame
 */
void MovementComponent::Update(const float& ar_DeltaTime) const
{
	*pr_Acceleration = *pr_Force;
	*pr_Velocity += *pr_Acceleration * ar_DeltaTime;
}
