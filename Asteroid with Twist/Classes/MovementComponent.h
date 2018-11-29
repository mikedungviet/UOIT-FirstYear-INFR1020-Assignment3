#pragma once
#include "Vector2.h"

/*
 * This class consists of all the vectors that is needed to make
 * a Sprite changes it
 */
class MovementComponent
{
private:
	Vector2 *pr_Direction, *pr_Acceleration, *pr_Velocity, *pr_AppliedForceDirection;
	float *pr_Friction, *pr_AppliedForce;
public:
	//Constructors and Destructor
	MovementComponent(const float& ar_FrictionCoefficient = 0);
	~MovementComponent();

	//Getters
	Vector2* GetDirectionVector() const;
	Vector2* GetAcceleration() const;
	Vector2* GetVelocity() const;
	float* GetFriction() const;
	float* GetAppliedForce() const;

	//Setters
	void SetDirectionVector(const Vector2& ar_NewDirection) const;
	void SetDirectionVector(const float& ar_NewX, const float& ar_NewY) const;
	void SetAcceleration(const Vector2& ar_NewAcceleration) const;
	void SetAcceleration(const float& ar_NewX, const float& ar_NewY) const;
	void SetVelocity(const Vector2& ar_NewVelocity) const;
	void SetVelocity(const float& ar_NewX, const float& ar_NewY) const;
	void SetForceDirection(const Vector2 &ar_ForceDirection) const;
	void SetForceDirection(const float& ar_NewX, const float& ar_NewY) const;

	void SetAppliedForce(const float &ar_NewForce) const;

	//Member Functions
	void UpdateDirection(const float &ar_AngleChanges) const;
	void Update(const float& ar_DeltaTime) const;
};
