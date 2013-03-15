#ifndef __TEXT_WALL_LAYER_H__
#define __TEXT_WALL_LAYER_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;

class TextWallLayer : public cocos2d::CCLayerColor
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    
    void SkipButtonCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(TextWallLayer);

private:
	unsigned int m_stringIndex;
	CCLabelTTF * m_pText;
};

#endif