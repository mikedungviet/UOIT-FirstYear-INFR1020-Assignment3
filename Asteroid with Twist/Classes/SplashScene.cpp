#include "SplashScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenu.h"
#include "Definitions.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    return SplashScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
	//Initialization
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->scheduleOnce(schedule_selector(SplashScene::goToMainMenu), DISPLAY_TIME_SPLASH);

	auto backgroundSprite = Sprite::create("HelloWorld.png");
	backgroundSprite->setPosition( Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y) );

	this->addChild( backgroundSprite);
	return true;
}

void SplashScene::goToMainMenu(float dt)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
