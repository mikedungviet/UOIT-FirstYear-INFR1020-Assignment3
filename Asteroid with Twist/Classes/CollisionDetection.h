#pragma once
#include "GameEntitiesSingleton.h"
#include "GameEntities.h"
class CollisionDetection
{
public:
	static bool CheckCollision(const CollisionComponent *ar_CollisionComponent1, const CollisionComponent *ar_CollisionComponent2);
	static void LoopAndDetectCollision();
};

