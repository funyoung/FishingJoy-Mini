//
//  FishingPauseLayer.cpp
//  FishJoyMini
//
//  Created by Ken on 14-3-16.
//
//

#include "FishingPauseLayer.h"

using namespace cocos2d::ui;

bool FishingPauseLayer::init(){
	
	//Read the resources of CocoStudio json file
	auto pauseWidget = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("CocoStudioRes/FishMiniPauseLayer_1/FishMiniPauseLayer_1.json"));
	
	//Get the buttons of continue button, main menu button, select button, setting button
	Button* continueBtn = dynamic_cast<Button*>(pauseWidget->getChildByName("ContinueBtn"));
	Button* mainMenuBtn = dynamic_cast<Button*>(pauseWidget->getChildByName("MainMenuBtn"));
	Button* selectBtn = dynamic_cast<Button*>(pauseWidget->getChildByName("SelectSceneBtn"));
	Button* settingBtn = dynamic_cast<Button*>(pauseWidget->getChildByName("SettingBtn"));
    
	//Add the touch event to each button
	continueBtn->addTouchEventListener(CC_CALLBACK_2(FishingPauseLayer::continueEvent, this));
	mainMenuBtn->addTouchEventListener(CC_CALLBACK_2(FishingPauseLayer::mainMenuEvent, this));
	selectBtn->addTouchEventListener(CC_CALLBACK_2(FishingPauseLayer::selectEvent, this));
	settingBtn->addTouchEventListener(CC_CALLBACK_2(FishingPauseLayer::settingEvent, this));
	
	addChild(pauseWidget,0);
	
	return true;
}

void FishingPauseLayer::continueEvent(Ref* target, ui::Widget::TouchEventType type){
	
	if(type==ui::Widget::TouchEventType::ENDED){
        
		//Set the background to normal
		auto background = (Sprite*)(getParent()->getChildByTag(101)->getChildByTag(102));
		background->setTexture("CocoStudioRes/background.jpg");
		background->setScale(1.0f);
		background->setZOrder(-1.0f);
        
		//Resume all the action and touch events
		getParent()->getChildByTag(101)->onEnter();
        
		//Remove the pause layer and its children
		removeAllChildrenWithCleanup(true);
		removeFromParent();
	}
}

void FishingPauseLayer::selectEvent(Ref* target, ui::Widget::TouchEventType type){
	
	
}

void FishingPauseLayer::mainMenuEvent(Ref* target, ui::Widget::TouchEventType type){
	
	//back from the replace scene
	if(type==ui::Widget::TouchEventType::ENDED){
        
		auto replaceScene = TransitionFadeBL::create(2, MainMenuScene::create());
        
		Director::getInstance()->replaceScene(replaceScene);
	}
}

void FishingPauseLayer::settingEvent(Ref* target, ui::Widget::TouchEventType type){
	
	
}