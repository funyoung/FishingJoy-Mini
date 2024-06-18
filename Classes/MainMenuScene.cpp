//
//  MainMenuScene.cpp
//  FishJoyMini
//
//  Created by Ken on 14-3-6.
//
//

#include "MainMenuScene.h"
#include "MainMenuLayer.h"

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

bool MainMenuScene::init(){

	//Init the main menu layer
	MainMenuLayer* mainMenuLayer = MainMenuLayer::create();
	
	//Add the main menu layer to the scene
	addChild(mainMenuLayer,10);
	
	return true;
}
