#include "CollisionDetection.h"

void CollisionDetection::LoopAndDetectCollision()
{
	//Load the Vector
	auto lo_AllEntities = GameEntitiesSingleton::GetInstance()->GetGameEntitiesVector();

	//Loop through the loop and check for collision
	for (unsigned lo_I = 0; lo_I < lo_AllEntities.size(); lo_I++)
	{
		for (int lo_J = lo_I + 1; lo_J < lo_AllEntities.size(); lo_J++)
		{
			if (CheckCollision(lo_AllEntities[lo_I]->GetCollisionComponent(), lo_AllEntities[lo_J]->GetCollisionComponent())) {
				//Resolving Collision
				lo_AllEntities[lo_I]->ResolveCollision(lo_AllEntities[lo_J]);
				lo_AllEntities[lo_J]->ResolveCollision(lo_AllEntities[lo_I]);

				//If the two colliding entities have lives equal 0, then delete both
				if (lo_AllEntities[lo_I]->GetLives() == 0)
					GameEntitiesSingleton::GetInstance()->DeleteEntity(lo_AllEntities[lo_I]);
				if (lo_AllEntities[lo_J]->GetLives() == 0)
					GameEntitiesSingleton::GetInstance()->DeleteEntity(lo_AllEntities[lo_J]);
			}
		}
	}
}

/*
 *@brief This function checks if the two circles are overlapping by comparing
 *the Distance Square between to center point with the sum of the radii square
 *
 *@return True if the circles are overlapping
 *@return False if the circles aren't overlapping
 */
bool CollisionDetection::CheckCollision(const CollisionComponent *ar_CollisionComponent1,
	const CollisionComponent *ar_CollisionComponent2)
{
	//Calculate the distance square between two circles
	const auto lo_DistanceSquareBetweenTwoEntities = Vector2::CalculateDistanceSquareBetweenTwoVectors
	(*ar_CollisionComponent1->GetPosition(), *ar_CollisionComponent2->GetPosition());

	//Calculate the sum of Radii square
	const auto lo_SumOfRadii = std::pow( (*ar_CollisionComponent1->GetRadius() + *ar_CollisionComponent2->GetRadius()),2);

	//Compare
	return lo_DistanceSquareBetweenTwoEntities < lo_SumOfRadii;
}

