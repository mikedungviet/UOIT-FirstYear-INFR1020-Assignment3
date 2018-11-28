#pragma once
#include "Vector2.h"

/*
 * This class consists of all the vectors that is needed to make
 * a Sprite changes it
 */
class MovementComponent
{
private:
	Vector2 *pr_Force, *pr_Acceleration, *pr_Velocity, *pr_Friction;
public:
	//Constructors and Destructor
	MovementComponent();
	~MovementComponent();

	//Getters
	Vector2* GetForce();
	Vector2* GetForce() const;
	Vector2* GetAcceleration();
	Vector2* GetAcceleration() const;
	Vector2* GetVelocity();
	Vector2* GetVelocity() const;
	Vector2* GetFriction();
	Vector2* GetFriction() const;

	//Setters
	void SetForce(const Vector2& ar_NewForce) const;
	void SetForce(const float& ar_NewX, const float& ar_NewY) const;
	void SetAcceleration(const Vector2& ar_NewAcceleration) const;
	void SetAcceleration(const float& ar_NewX, const float& ar_NewY) const;
	void SetVelocity(const Vector2& ar_NewVelocity) const;
	void SetVelocity(const float& ar_NewX, const float& ar_NewY) const;
	void SetFriction(const Vector2 &ar_NewFriction) const;
	void SetFriction(const float & ar_NewX, const float& ar_NewY)const;

	//Member Functions
	void Update(const float& ar_DeltaTime) const;
};
