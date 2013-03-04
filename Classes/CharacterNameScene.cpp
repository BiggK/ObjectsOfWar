#include "CharacterNameScene.h"
#include "StringTable.h"

using namespace cocos2d;

static CCRect getRect(CCNode * pNode)
{
    CCRect rc;
    rc.origin = pNode->getPosition();
    rc.size = pNode->getContentSize();
    rc.origin.x -= rc.size.width / 2;
    rc.origin.y -= rc.size.height / 2;
    return rc;
}

/////////////////////////////////////////////////////////////////////////
///////////////////////CharacterNameScene////////////////////////////////
/////////////////////////////////////////////////////////////////////////
CCScene* CharacterNameScene::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        CharacterNameScene *layer = CharacterNameScene::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CharacterNameScene::init()
{
    bool bRet = false;
	m_stringIndex = 0;
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
			menu_selector(CharacterNameScene::SkipButtonCallback));
        CC_BREAK_IF(! pSkipButton);

		float iconCenterY = 100;
		float sideIconXOffset = 150;

        // Position the buttons
        pSkipButton->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - sideIconXOffset, iconCenterY));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pSkipButton, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);
        this->addChild(pMenu, 1);

		//Register with touch dispatcher
		CCDirector* pDirector = CCDirector::sharedDirector();
		pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);

		//add audio
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
		//"audio/theme.mp3", true); 
		float windowWidth = CCDirector::sharedDirector()->getWinSize().width;

		//add text
		m_pText = CCLabelTTF::labelWithString(StringTable[1], CCSizeMake(1000, 0), kCCTextAlignmentCenter, "Arial", 100);
		m_pText->setColor(ccc3(255, 255, 255));
		m_pText->setPosition(ccp(windowWidth / 2,550));
        addChild(m_pText);

		//add input
		m_pCharacterNameField = CCTextFieldTTF::textFieldWithPlaceHolder("Name", CCSizeMake(1000, 0), kCCTextAlignmentCenter, "Arial", 100 );
		m_pCharacterNameField->setColor(ccc3(255, 255, 255));
		m_pCharacterNameField->setPosition(ccp(windowWidth/2, 400));
        addChild(m_pCharacterNameField);

        bRet = true;
    } while (0);

    return bRet;
}

void CharacterNameScene::SkipButtonCallback(CCObject* pSender)
{

}

void CharacterNameScene::onClickTrackNode(bool bClicked)
{
    CCTextFieldTTF * pTextField = (CCTextFieldTTF*)m_pCharacterNameField;
    if (bClicked)
    {
        // TextFieldTTFTest be clicked
        CCLOG("TextFieldTTFDefaultTest:CCTextFieldTTF attachWithIME");
        pTextField->attachWithIME();
    }
    else
    {
        // TextFieldTTFTest not be clicked
        CCLOG("TextFieldTTFDefaultTest:CCTextFieldTTF detachWithIME");
        pTextField->detachWithIME();
    }
}


bool CharacterNameScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("++++++++++++++++++++++++++++++++++++++++++++");
    m_beginPos = pTouch->getLocation();    
    return true;
}

void CharacterNameScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    if (! m_pCharacterNameField)
    {
        return;
    }
    
    CCPoint endPos = pTouch->getLocation();    

    float delta = 5.0f;
    if (::abs(endPos.x - m_beginPos.x) > delta
        || ::abs(endPos.y - m_beginPos.y) > delta)
    {
        // not click
        m_beginPos.x = m_beginPos.y = -1;
        return;
    }

    // decide the trackNode is clicked.
    CCRect rect;
	CCPoint point = pTouch->getLocation();
    CCLOG("KeyboardNotificationLayer:clickedAt(%f,%f)", point.x, point.y);

    rect = getRect(m_pCharacterNameField);
    CCLOG("KeyboardNotificationLayer:TrackNode at(origin:%f,%f, size:%f,%f)",
        rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);

    this->onClickTrackNode(rect.containsPoint(point));
    CCLOG("----------------------------------");
}