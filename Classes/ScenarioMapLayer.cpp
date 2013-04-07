#include "ScenarioMapLayer.h"
#include "SimpleAudioEngine.h"

//constructor- get set up for init
ScenarioMapLayer::ScenarioMapLayer()
{}
//destructor- delete any pointers here
ScenarioMapLayer::~ScenarioMapLayer()
{}
void ScenarioMapLayer::onExit(){
	this->removeAllChildrenWithCleanup(true);
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(static_cast<CCTargetedTouchDelegate*>(this));
	//this->removeAllChildrenWithCleanup(true);
}
//initialize the gobs of stuff needed by the map
bool ScenarioMapLayer::init()
{
	if ( CCLayerColor::initWithColor( ccc4(0,0,0,0) ) )
	{
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		//override pixel format
		CCTexture2D::setDefaultAlphaPixelFormat(kTexture2DPixelFormat_RGBA8888);

		//register with touch delegate
		CCDirector* pDirector = CCDirector::sharedDirector();
		pDirector->getTouchDispatcher()->addTargetedDelegate(dynamic_cast<CCTargetedTouchDelegate*>(this), 0, false);
		return true;
	}
	else
	{
		return false;
	}
}

bool ScenarioMapLayer::LoadModel(ScenarioMapModel* scenarioMapModel)
{
	m_pScenarioMapModel = scenarioMapModel;
	//add the tilemap
	m_pTileMap = CCTMXTiledMap::create(m_pScenarioMapModel->GetMapPath());
	m_pTileMap->retain();
	//get the background layer
	m_pBackgroundLayer = m_pTileMap->layerNamed("Tile Layer 1");
	m_pBackgroundLayer->retain();
	m_pTileMap->layerNamed("Tile Layer 1")->getTiles();
	//add the audio
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(m_pScenarioMapModel->GetMusicPath()); 
		
	this->addChild(m_pTileMap);
	return true;
}