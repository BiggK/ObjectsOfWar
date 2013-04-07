#ifndef __SCENARIO_MODEL_H__
#define __SCENARIO_MODEL_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "TileMapConfig.h"

using namespace cocos2d;

class ScenarioModel
{
public:
	ScenarioModel();
	virtual ~ScenarioModel();
	TileMapModel* GetTileMapModel(){return m_pTileMapModel;}
protected:
	TileMapModel* m_pTileMapModel;
};

#endif