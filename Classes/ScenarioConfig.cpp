#include "ScenarioConfig.h"

ScenarioConfig_001::ScenarioConfig_001(): ScenarioModel()
{
	m_pScenarioMapModel = new ScenarioMapConfig_001();
}

ScenarioConfig_001::~ScenarioConfig_001()
{
	delete m_pScenarioMapModel;
}