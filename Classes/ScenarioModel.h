#ifndef __SCENARIO_MODEL_H__
#define __SCENARIO_MODEL_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ScenarioMapConfig.h"

using namespace cocos2d;

class ScenarioModel
{
public:
	ScenarioModel();
	virtual ~ScenarioModel();
	ScenarioMapModel* GetScenarioMapModel(){return m_pScenarioMapModel;}
protected:
	ScenarioMapModel* m_pScenarioMapModel;
};

#endif