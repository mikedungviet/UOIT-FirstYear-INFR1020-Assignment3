#pragma once
#include <vector>
#include "GameEntities.h"
#include "Enemies.h"


class SpaceShip;


class GameEntitiesSingleton
{
private:

	//variables
	std::vector<GameEntities*> pr_GameEntitiesList;
	std::vector<Enemies*> pr_EnemyList;
	SpaceShip *pr_SpaceShip;
	static GameEntitiesSingleton *pr_Instance;
	cocos2d::Layer *pr_GameMapLayer;
	Vector2 *pr_PositionOfHookedAsteroid;

	//Constructor
	GameEntitiesSingleton();
public:
	//Getters
	static GameEntitiesSingleton* GetInstance();
	SpaceShip* GetSpaceShip() const;
	std::vector<GameEntities*> GetGameEntitiesVector() const;
	GameEntities* GetEntity(const int& ar_Index) const;
	std::vector<Enemies*> GetGameEnemyVector() const;
	cocos2d::Layer* GetMapLayer() const;
	Vector2* GetAsteroidPosition() const;


	//Setter
	void SetSpaceShip(SpaceShip* ar_Ship);
	void SetMapLayer(cocos2d::Layer *ar_Layer);
	void SetHookedAsteroidPosition(Vector2 *ar_Position);

	//Member Functions
	void AddEntity(GameEntities *ar_EntityToAdd);
	void AddEnemy(Enemies *ar_EnemyToAdd);
	void DeleteEntity(GameEntities *ar_EntityToDelete);
	void DeleteEnemy(Enemies *ar_EnemyToDelete);
};

