#include "SuperCoolScene.h"

Scene * testScene::createScene()
{
	Scene* scene = Scene::createWithPhysics();
	testScene* layer = testScene::create();

	scene->addChild(layer);

	return scene;
}
