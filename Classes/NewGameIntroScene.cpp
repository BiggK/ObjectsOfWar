#include "NewGameIntroScene.h"
#include "StringTable.h"

using namespace cocos2d;

CCScene* NewGameIntroScene::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        NewGameIntroScene *layer = NewGameIntroScene::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewGameIntroScene::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());

		//set the background color
		if( !CCLayerColor::initWithColor(ccc4(0, 0, 0, 0)) ) //RGBA
		{
			return false;
		}

        CCMenuItemImage *pSkipButton = CCMenuItemImage::create(
            "ui/play-hi_128x128_white.png",
            "ui/play-hi_128x128_green.png",
            this,
			menu_selector(NewGameIntroScene::SkipButtonCallback));
        CC_BREAK_IF(! pSkipButton);

		float iconCenterY = 100;
		float sideIconXOffset = 150;

        // Position the buttons
        pSkipButton->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - sideIconXOffset, iconCenterY));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pSkipButton, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to NewGameIntroScene layer as a child layer.
        this->addChild(pMenu, 1);

		//add audio
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
		"audio/theme.mp3", true); 

		//add text
		CCLabelTTF * text = CCLabelTTF::labelWithString(StringTable[0], CCSizeMake(1000, 0), CCTextAlignment::kCCTextAlignmentCenter, "Thonburi", 100);
		text->setColor(ccc3(255, 255, 255));
		text->setPosition(ccp(640,360));
        addChild(text);

        bRet = true;
    } while (0);

    return bRet;
}

void NewGameIntroScene::SkipButtonCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}