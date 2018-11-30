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
	cocos2d::Layer *pr_GameMapLayer;
	GameEntitiesSingleton();
public:
	//GetInstance functions
	static GameEntitiesSingleton* GetInstance();
	SpaceShip* GetSpaceShip() const;
	std::vector<GameEntities*> GetGameEntitiesVector() const;
	GameEntities* GetEntity(const int& ar_Index) const;
	cocos2d::Layer* GetMapLayer() const;

	//Setter
	void SetSpaceShip(SpaceShip* ar_Ship);
	void SetMapLayer(cocos2d::Layer *ar_Layer);

	//Member Functions
	void AddEntity(GameEntities *ar_EntityToAdd);
	void DeleteEntity(GameEntities *ar_EntityToDelete);

};

