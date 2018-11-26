#pragma once
#include "Vector2.h"

/*
 * This class consists of all the vectors that is needed to make 
 * a Sprite changes it
 */
class MovementComponent
{
private:
	Vector2 *pr_Force, *pr_Acceleration, *pr_Velocity;
public:
	//Constructors and Destructor
	MovementComponent();
	~MovementComponent();

	//Getters
	Vector2 *GetForce();
	Vector2 *GetForce()const;
	Vector2 *GetAcceleration();
	Vector2 *GetAcceleration() const;
	Vector2 *GetVelocity();
	Vector2 *GetVelocity() const;

	//Member Functions
	void Update(const float &ar_DeltaTime)const;
};

