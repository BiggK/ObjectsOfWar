#ifndef __NEW_GAME_INTRO_SCENE_H__
#define __NEW_GAME_INTRO_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;

class NewGameIntroScene : public cocos2d::CCLayerColor
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    
    void SkipButtonCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(NewGameIntroScene);
};

#endif