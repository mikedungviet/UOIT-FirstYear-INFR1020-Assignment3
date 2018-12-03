#include "CollisionDetection.h"

void CollisionDetection::LoopAndDetectCollision()
{
	//Load the Vector
	//auto lo_AllEntities = GameEntitiesSingleton::GetInstance()->GetGameEntitiesVector().size();

	auto lo_EntitiesSingleton = GameEntitiesSingleton::GetInstance();

	//Loop through the loop and check for collision
	for (unsigned lo_I = 0; lo_I < lo_EntitiesSingleton->GetGameEntitiesVector().size(); lo_I++)
	{
		for (auto lo_J = lo_I + 1; lo_J < lo_EntitiesSingleton->GetGameEntitiesVector().size(); lo_J++)
		{
			if (CheckCollision(lo_EntitiesSingleton->GetEntity(lo_I)->GetCollisionComponent(),
			                   lo_EntitiesSingleton->GetEntity(lo_J)->GetCollisionComponent()))
			{
				//Resolving Collision
				lo_EntitiesSingleton->GetEntity(lo_I)->ResolveCollision(lo_EntitiesSingleton->GetEntity(lo_J));
				lo_EntitiesSingleton->GetEntity(lo_J)->ResolveCollision(lo_EntitiesSingleton->GetEntity(lo_I));

				const auto lo_EntityAtJ = lo_EntitiesSingleton->GetEntity(lo_J);

				//If the two colliding entities have lives equal 0, then delete both
				if (lo_EntitiesSingleton->GetEntity(lo_I)->GetLives() == 0)
					lo_EntitiesSingleton->DeleteEntity(lo_EntitiesSingleton->GetEntity(lo_I));

				//Because the entity 
				if (lo_EntitiesSingleton->GetEntity(lo_J-1)->GetLives() == 0)
					lo_EntitiesSingleton->DeleteEntity(lo_EntitiesSingleton->GetEntity(lo_J - 1));

				lo_I--;
				break;
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
bool CollisionDetection::CheckCollision(const CollisionComponent* ar_CollisionComponent1,
                                        const CollisionComponent* ar_CollisionComponent2)
{
	//Calculate the distance square between two circles
	const auto lo_DistanceSquareBetweenTwoEntities = Vector2::CalculateDistanceSquareBetweenTwoVectors
		(*ar_CollisionComponent1->GetPosition(), *ar_CollisionComponent2->GetPosition());

	//Calculate the sum of Radii square
	const auto lo_SumOfRadii = std::pow((*ar_CollisionComponent1->GetRadius() + *ar_CollisionComponent2->GetRadius()),
	                                    2);

	//Compare
	return lo_DistanceSquareBetweenTwoEntities < lo_SumOfRadii;
}

