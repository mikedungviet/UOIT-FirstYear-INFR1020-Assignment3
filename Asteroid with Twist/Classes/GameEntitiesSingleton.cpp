#include "GameEntitiesSingleton.h"


/*
 * @brief Constructor for the GameEntitiesSingleton. It sets all pointers to nullptr.
 */
GameEntitiesSingleton::GameEntitiesSingleton(): pr_SpaceShip{nullptr}, pr_GameMapLayer{nullptr}, 
pr_PositionOfHookedAsteroid{nullptr}
{/*Empty*/}

GameEntitiesSingleton *GameEntitiesSingleton::pr_Instance = nullptr;

/*
 * @brief This function returns the memory address of the
 * Singleton
 * 
 * @return Returns the memory address of the object
 */
GameEntitiesSingleton* GameEntitiesSingleton::GetInstance()
{
	//if the singleton hasn't been initiate
	if (!pr_Instance)
		pr_Instance = new GameEntitiesSingleton;
	//Return the memory address
	return pr_Instance;
}

/*
 * @brief This function returns the memory address of the spaceShip
 * 
 * @return Returns the memory address of the spaceship
 */
SpaceShip* GameEntitiesSingleton::GetSpaceShip() const
{
	return pr_SpaceShip;
}

/*
 * @brief This function returns the Game
 */
std::vector<GameEntities*> GameEntitiesSingleton::GetGameEntitiesVector() const
{
	return pr_GameEntitiesList;
}

/*
 *@brief This function returns the memory address of the element in the parameter
 *
 *@param ar_Index The index within the vector to access
 *
 *@return Returns the memory address
 */
GameEntities* GameEntitiesSingleton::GetEntity(const int& ar_Index) const
{
	if (ar_Index >= pr_GameEntitiesList.size())
		return nullptr;

	return pr_GameEntitiesList[ar_Index];
}

/*
 * @brief This function returns the memory address of the game
 * map layer
 */
cocos2d::Layer* GameEntitiesSingleton::GetMapLayer() const
{
	return pr_GameMapLayer;
}

/*
 *
 */
Vector2* GameEntitiesSingleton::GetAsteroidPosition() const
{
	return pr_PositionOfHookedAsteroid;
}


/*
 * @brief Set the address of the spaceship to the singleton spaceship
 * 
 * @param ar_Ship the address of the current spaceship
 */
void GameEntitiesSingleton::SetSpaceShip(SpaceShip* ar_Ship)
{
	pr_SpaceShip = ar_Ship;
}

/*
 *@brief This function sets the memory address of game map to another
 *
 *@param ar_Layer The pointer to set the map layer pointer to
 */
void GameEntitiesSingleton::SetMapLayer(cocos2d::Layer* ar_Layer)
{
	pr_GameMapLayer = ar_Layer;
}

void GameEntitiesSingleton::SetHookedAsteroidPosition(Vector2* ar_Position)
{
	pr_PositionOfHookedAsteroid = ar_Position;
}

/*
 * @brief This function adds the object in the parameter to the 
 * object game list and also to the current scene 
 */
void GameEntitiesSingleton::AddEntity(GameEntities* ar_EntityToAdd)
{
	pr_GameEntitiesList.push_back(ar_EntityToAdd);
	pr_GameMapLayer->addChild(ar_EntityToAdd->GetSprite());
}

/*
 * @brief This function deletes the object in the parameter from
 * the object game list and also from the running scene
 * 
 * @param ar_EntityToDelete The address of the entity to be deleted
 */
void GameEntitiesSingleton::DeleteEntity(GameEntities* ar_EntityToDelete)
{
	pr_GameEntitiesList.erase(std::find(pr_GameEntitiesList.begin(), pr_GameEntitiesList.end(), ar_EntityToDelete));
	pr_GameMapLayer->removeChild(ar_EntityToDelete->GetSprite(), true);
	delete ar_EntityToDelete;
}










