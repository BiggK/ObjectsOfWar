#include "HelloWorldScene.h"
#include "NewGameIntroScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.



		//Create settings button
        CCMenuItemImage *pSettingsButton = CCMenuItemImage::create(
            "ui/gears-hi_128x128_white.png",
            "ui/gears-hi_128x128_green.png",
            this,
			menu_selector(HelloWorld::SettingsButtonCallback));
        CC_BREAK_IF(! pSettingsButton);

		//Create load button
        CCMenuItemImage *pLoadButton = CCMenuItemImage::create(
            "ui/load-hi_128x128_white.png",
            "ui/load-hi_128x128_green.png",
            this,
			menu_selector(HelloWorld::LoadButtonCallback));
        CC_BREAK_IF(! pLoadButton);

        //Create play button
        CCMenuItemImage *pPlayButton = CCMenuItemImage::create(
            "ui/play-hi_128x128_white.png",
            "ui/play-hi_128x128_green.png",
            this,
			menu_selector(HelloWorld::PlayButtonCallback));
        CC_BREAK_IF(! pPlayButton);

		float iconCenterY = 100;
		float sideIconXOffset = 150;

        // Position the buttons
        pSettingsButton->setPosition(ccp(sideIconXOffset, iconCenterY));
        pLoadButton->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width / 2, iconCenterY));
        pPlayButton->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - sideIconXOffset, iconCenterY));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pSettingsButton, pLoadButton, pPlayButton, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
        CCSprite* pSprite = CCSprite::create("ui/title.png");
        CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);

		//add audio
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
		"audio/theme.mp3", true); 

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::SettingsButtonCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

void HelloWorld::LoadButtonCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

void HelloWorld::PlayButtonCallback(CCObject* pSender)
{
	CCDirector *pDirector = CCDirector::sharedDirector();
    CCScene *pScene = NewGameIntroScene::scene();
	pDirector->pushScene(pScene);
}
