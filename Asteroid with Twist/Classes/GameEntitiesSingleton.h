#pragma once
#include <vector>
#include "GameEntities.h"

class SpaceShip;

class GameEntitiesSingleton
{
private:
	std::vector<GameEntities*> pr_GameEntitiesList;
	SpaceShip *pr_SpaceShip;
	static GameEntitiesSingleton *pr_Instance;
	GameEntitiesSingleton();
public:
	//GetInstance functions
	static GameEntitiesSingleton* GetInstance();
	SpaceShip* GetSpaceShip() const;
	std::vector<GameEntities*> GetGameEntitiesVector() const;
	GameEntities* GetEntity(const int& ar_Index) const;

	//Setter
	void SetSpaceShip(SpaceShip* ar_Ship);

	//Member Functions
	void AddEntity(GameEntities *ar_EntityToAdd);
	void DeleteEntity(GameEntities *ar_EntityToDelete);

};

