#ifndef _SCENARIO_MAP_MODEL_H_
#define _SCENARIO_MAP_MODEL_H_
#include "cocos2d.h"

using namespace cocos2d;

//Class that handles drawing of the map layer in a scenario.
class ScenarioMapModel
{
public:
    ScenarioMapModel();
    virtual ~ScenarioMapModel();
	char* GetMapPath(){return m_pMapPath;}
	char* GetMusicPath(){return m_pMusicPath;}
protected:
	char* m_pMapPath;
	char* m_pMusicPath;
};

#endif // _MAP_LAYER_H_