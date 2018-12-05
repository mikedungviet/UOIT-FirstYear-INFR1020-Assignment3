#pragma once
#include "GameEntitiesSingleton.h"
#include "GameEntities.h"
class CollisionDetection
{
private:
	static void LoopEntitiesWithBlackHoles();
	static void LoopEntitiesWithEntities();
	static bool CheckCollision(const CollisionComponent *ar_CollisionComponent1, const CollisionComponent *ar_CollisionComponent2);
public:
	
	static void LoopAndDetectCollision();
	
};

