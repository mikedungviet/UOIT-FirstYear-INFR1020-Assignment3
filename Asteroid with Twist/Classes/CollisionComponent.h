#pragma once
#include "Vector2.h"

/*
 * This class holds all the necessary information of 
 * a Sprite to be able to to collision detection with
 * other Sprite
 */
class CollisionComponent
{
private:
	Vector2 *pr_Position;
	float *pr_Radius;
public:
	//Constructors and Destructor
	CollisionComponent();
	~CollisionComponent();

	//Getters
	Vector2 *GetPosition();
	Vector2 *GetPosition() const;
	float *GetRadius();

	//Setters
	void SetRadius(const float &ar_NewRadius);

	//Member Functions
	void Update(const float &ar_DeltaTime, const Vector2* ar_SpriteVelocity);
};