#include "ScenarioScene.h"
#include "GameDataModel.h"

bool ScenarioScene::init()
{
	if( CCScene::init() )
	{
		this->schedule( schedule_selector(ScenarioScene::Update), 1.0f );
		test = CCLabelTTF::create("OMFG BATTLEZ!!","Marker Felt", 48);
		test->setAnchorPoint(CCPoint(0,0));
		test->setPosition(ccp(200,24));
		this->addChild(test);
		return true;
	}
	else
	{
		return false;
	}
}

ScenarioScene::~ScenarioScene()
{
}
void ScenarioScene::Update(float dt)
{
}