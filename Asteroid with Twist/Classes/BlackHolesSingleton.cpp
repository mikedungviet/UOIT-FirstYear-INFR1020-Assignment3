#include "BlackHolesSingleton.h"
#include "BlackHoles.h"


/*
 * @brief This is the constructor for BlackHolesSingleton. It sets all pointer
 * to nullptr
 */
BlackHolesSingleton::BlackHolesSingleton(): pr_MapLayer(nullptr)
{/*Empty*/}

//Set the pr_Instance to nullptr before being initialized
BlackHolesSingleton* BlackHolesSingleton::pr_Instance = nullptr;


BlackHolesSingleton::~BlackHolesSingleton()
{
}

/*
 * @brief This function returns the memory address of the singleton. 
 * If the singleton has not been initialized, call the constructor
 * 
 * @return Returns the pointer of the singleton
 */
BlackHolesSingleton* BlackHolesSingleton::GetInstance()
{
	if (pr_Instance == nullptr)
		pr_Instance = new BlackHolesSingleton;
	return pr_Instance;
}

/*
 * @brief This function returns the vector containing all the pointers
 * for the black holes
 * 
 * @return Returns the vector container
 */
std::vector<BlackHoles*> BlackHolesSingleton::GetBlackHoleVector()
{
	return pr_BlackHolesList;
}

/*
 *@brief This function returns the specified Black Hole's pointer within
 *the Black Hole List
 *
 *@param ar_IndexToGet The Index within the vector wish to return
 *
 *@return Return the Black Hole's pointer at the specified index
 */
BlackHoles* BlackHolesSingleton::GetSingleBlackHole(int ar_IndexToGet)
{
	if (ar_IndexToGet >= pr_BlackHolesList.size())
		return nullptr;
	return pr_BlackHolesList[ar_IndexToGet];
}

/*
 *@brief This function sets the memory address of game map to another
 *
 *@param ar_Layer The pointer to set the map layer pointer to
 */
void BlackHolesSingleton::SetMapLayer(cocos2d::Layer* ar_LayerPointer)
{
	pr_MapLayer = ar_LayerPointer;
}

/*
 * @brief This function adds the pointer in the parameter to the vector
 * and to the current game layer
 * 
 * @param ar_BlackHoleToAdd The BlackHole pointer to added
 */
void BlackHolesSingleton::AddBlackHole(BlackHoles* ar_BlackHoleToAdd)
{
	pr_BlackHolesList.push_back(ar_BlackHoleToAdd);
	pr_MapLayer->addChild(ar_BlackHoleToAdd->GetSprite());
}

/*
 * @brief This function deletes the object that is associated with the pointer
 * in the parameter
 * 
 *  @param ar_BlackHoleToDelete The Black Hole pointer to be deleted
 */
void BlackHolesSingleton::DeleteBlackHole(BlackHoles* ar_BlackHoleToDelete)
{
	pr_BlackHolesList.erase(std::find(pr_BlackHolesList.begin(), pr_BlackHolesList.end(), ar_BlackHoleToDelete));
	pr_MapLayer->removeAllChildrenWithCleanup(ar_BlackHoleToDelete->GetSprite());
	delete ar_BlackHoleToDelete;
}


