#include "AppDelegate.h"
#include "Game.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
	auto lo_Director = Director::getInstance();
	auto lo_GlView = lo_Director->getOpenGLView();
	if (!lo_GlView) {
		lo_GlView = GLViewImpl::createWithFullScreen("Hello World");
		lo_Director->setOpenGLView(lo_GlView);
	}

	const auto lo_Scene = Game::Create();
	lo_Director->runWithScene(lo_Scene);

	return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}