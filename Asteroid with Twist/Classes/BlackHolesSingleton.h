#pragma once
#include <vector>
#include "cocos2d.h"

class BlackHoles;

class BlackHolesSingleton
{
private:
	//Variables
	std::vector<BlackHoles*> pr_BlackHolesList;
	cocos2d::Layer *pr_MapLayer;
	static BlackHolesSingleton* pr_Instance;
	//Constructor
	BlackHolesSingleton();
public:
	~BlackHolesSingleton();

	static BlackHolesSingleton* GetInstance();
	std::vector<BlackHoles*> GetBlackHoleVector();
	BlackHoles *GetSingleBlackHole(int ar_IndexToGet);

	void SetMapLayer(cocos2d::Layer *ar_LayerPointer);

	void AddBlackHole(BlackHoles *ar_BlackHoleToAdd);
	void DeleteBlackHole(BlackHoles *ar_BlackHoleToDelete);
};

