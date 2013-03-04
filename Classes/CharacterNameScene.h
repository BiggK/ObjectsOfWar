#ifndef __CHARACTER_NAME_SCENE_H__
#define __CHARACTER_NAME_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;


class CharacterNameScene : public cocos2d::CCLayerColor
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    
    void SkipButtonCallback(CCObject* pSender);
	void onClickTrackNode(bool bClicked);

    // implement the "static node()" method manually
    CREATE_FUNC(CharacterNameScene);

private:
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	unsigned int m_stringIndex;
	CCLabelTTF * m_pText;
	CCTextFieldTTF* m_pCharacterNameField;
	CCPoint  m_beginPos;
};

#endif