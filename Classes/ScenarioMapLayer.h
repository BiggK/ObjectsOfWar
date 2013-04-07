#ifndef _SCENARIO_MAP_LAYER_H_
#define _SCENARIO_MAP_LAYER_H_
#include "cocos2d.h"
#include "ScenarioMapConfig.h"
#include "ScenarioMapModel.h"

using namespace cocos2d;

//Class that handles drawing of the map layer in a scenario.
class ScenarioMapLayer : public cocos2d::CCLayerColor , public CCTargetedTouchDelegate
{
public:
    ScenarioMapLayer();
    virtual ~ScenarioMapLayer();
	bool init();
	void onExit();
	bool LoadModel(ScenarioMapModel* scenarioMapModel);
	CREATE_FUNC(ScenarioMapLayer);
protected:
	cocos2d::CCTMXTiledMap* m_pTileMap;
	cocos2d::CCTMXLayer* m_pBackgroundLayer;
	cocos2d::CCTMXLayer* m_pForegroundLayer;
	cocos2d::CCTMXLayer* m_pMetaLayer;
	ScenarioMapModel* m_pScenarioMapModel;
};

#endif // _MAP_LAYER_H_