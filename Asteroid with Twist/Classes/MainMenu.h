#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"
#include "Definitions.h"

USING_NS_CC;

class MainMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);

private:
	void goToGameScene(Ref *sender);
};

#endif // __MAIN_MENU_SCENE_H__
