#include "MovementComponent.h"
#include "Matrix2.h"
#include "spine/extension.h"

/*
 * @brief Constructor for all the Vectors component. Set everything to 0
 */
MovementComponent::MovementComponent(const float& ar_FrictionCoefficient)
{
	pr_Direction = new Vector2(0, 1);
	pr_Acceleration = new Vector2;
	pr_Velocity = new Vector2;
	pr_AppliedForceDirection = new Vector2;
	pr_Friction = new float;
	pr_AppliedForce = new float;

	//Set variables
	*pr_Friction = ar_FrictionCoefficient;
	*pr_AppliedForce = 0;
}

/*
 * @brief Destructor for Movement Component. Delete any dynamic allocated
 * variables
 */
MovementComponent::~MovementComponent()
{
	delete pr_Acceleration;
	delete pr_Direction;
	delete pr_Velocity;
	delete pr_Friction;
	delete pr_AppliedForceDirection;
	delete pr_AppliedForce;
}

/*
 *@brief This function returns the direction vector. This cannot
 *be modified
 *
 *@return Return the Force vector as Vector2
 */
Vector2* MovementComponent::GetDirectionVector() const
{
	return pr_Direction;
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
 *@brief This function return the Gravity vector. This cannot
 *be modified
 *
 *@return Return the Gravity vector as Vector 2
 */
float* MovementComponent::GetFriction() const
{
	return pr_Friction;
}

/*
 * @brief This function returns the address of
 * Applied Force vector.
 *
 * @return Returns the memory address of applied force
 * as a float pointer
 */
float* MovementComponent::GetAppliedForce() const
{
	return pr_AppliedForce;
}

/*
 * @brief This function sets the Force Vector to new value
 *
 * @param ar_NewForce This is the new Vector2 to set the force to
 */
void MovementComponent::SetDirectionVector(const Vector2& ar_NewDirection) const
{
	(*pr_Direction).x = ar_NewDirection.x;
	(*pr_Direction).y = ar_NewDirection.y;
}

/*
 * @brief This function sets the Force Vector to new value
 *
 * @param ar_NewX This is the new float to set the force x to
 * @param ar_NewY This is the new float to the the force y to
 */
void MovementComponent::SetDirectionVector(const float& ar_NewX, const float& ar_NewY) const
{
	(*pr_Direction).x = ar_NewX;
	(*pr_Direction).y = ar_NewY;
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
 * @brief This function sets the Force Direction to a new value
 * 
 * @param ar_ForceDirection the new direction
 */
void MovementComponent::SetForceDirection(const Vector2& ar_ForceDirection) const
{
	*pr_AppliedForceDirection = ar_ForceDirection;
}

/*
 *@brief This function sets the force direction
 */
void MovementComponent::SetForceDirection(const float& ar_NewX, const float& ar_NewY) const
{
	pr_AppliedForceDirection->x = ar_NewX;
	pr_AppliedForceDirection->y = ar_NewY;
}

/*
 * @brief This function sets the applied force to a new float set in the 
 * parameter
 * 
 * @param ar_NewForce This is the new float to set the applied force to.
 */
void MovementComponent::SetAppliedForce(const float& ar_NewForce) const
{
	*pr_AppliedForce = ar_NewForce;
}

/*
 * @brief This function calculates the new direction (with length equals 1) of
 * the movement using matrix rotation
 *
 * @param ar_AngleChanges The angle changes to be rotated.
 */
void MovementComponent::UpdateDirection(const float& ar_AngleChanges) const
{
	const auto lo_AngleInRad = ar_AngleChanges / 180 * PI;
	const Mat2 lo_TempMat(Vector2(cosf(-lo_AngleInRad), -sinf(-lo_AngleInRad)),
	                Vector2(sinf(-lo_AngleInRad), cosf(-lo_AngleInRad)));

	*pr_Direction = lo_TempMat * (*pr_Direction);
}

/*
 * @brief This function uses basic kinematic and dynamic equations 
 * to update the velocity vector
 *
 * @param deltaTime This is the time difference between the current
 * frame and last frame
 */
void MovementComponent::Update(const float& ar_DeltaTime) const
{
	//Local Variables
	Vector2 lo_NetForceVector;
	const Vector2 lo_AppliedForceVector(*pr_AppliedForce * pr_AppliedForceDirection->x,
	                                    *pr_AppliedForce * pr_AppliedForceDirection->y);

	//If the object is moving, apply friction to the net force
	if (pr_Velocity->CalculateLength() != 0)
	{
		const Vector2 lo_VelocityDirection(pr_Velocity->NormalizeVector());
		const Vector2 lo_FrictionVector(lo_VelocityDirection * -(*pr_Friction));
		lo_NetForceVector = lo_AppliedForceVector + lo_FrictionVector;
	}
		//If the object is not moving, DO NOT apply friction to net force
	else
		lo_NetForceVector = lo_AppliedForceVector;

	//Update kinematic equations
	*pr_Acceleration = lo_NetForceVector;
	*pr_Velocity += *pr_Acceleration * ar_DeltaTime;
}
