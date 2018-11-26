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
 */
Vector2* MovementComponent::GetForce()
{
	return pr_Force;
}

/*
 *@brief This function returns the Force vector. This cannot
 *be modified
 */
Vector2* MovementComponent::GetForce() const
{
	return pr_Force;
}

/*
 *@brief This function returns the Acceleration vector. This can
 *be modified
 */
Vector2* MovementComponent::GetAcceleration()
{
	return pr_Acceleration;
}

/*
 *@brief This function returns the Acceleration vector. This cannot
 *be modified
 */
Vector2* MovementComponent::GetAcceleration() const
{
	return pr_Acceleration;
}

/*
 *@brief This function returns the Velocity vector. This can
 *be modified
 */
Vector2* MovementComponent::GetVelocity()
{
	return pr_Velocity;
}

/*
 *@brief This function returns the Velocity vector. This cannot
 *be modified
 */
Vector2* MovementComponent::GetVelocity() const
{
	return pr_Velocity;
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
