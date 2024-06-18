//
//  MainMenuScene.h
//  FishJoyMini
//
//  Created by Ken on 14-3-6.
//
//

#ifndef FishJoyMini_MainMenuScene_h
#define FishJoyMini_MainMenuScene_h

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	CREATE_FUNC(MainMenuScene);
};

#endif
