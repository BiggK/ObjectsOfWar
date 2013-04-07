#ifndef __SCENARIO_SCENE_H__
#define __SCENARIO_SCENE_H__
#include "cocos2d.h"
#include "ScenarioModel.h"
#include "TileMapLayer.h"

using namespace cocos2d;
//This is the scene where battles take place.
class ScenarioScene : public CCScene
{
public:
	ScenarioScene(void){};
	~ScenarioScene(void);
	bool init();
	bool LoadModel(ScenarioModel* scenarioSceneModel);
	void Update(float dt);
	CREATE_FUNC(ScenarioScene);
private:
	CCLabelTTF* test;
	ScenarioModel* m_pScenarioModel;
	TileMapLayer* m_pTileMapLayer;

};

#endif

