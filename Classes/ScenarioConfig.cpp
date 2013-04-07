#include "ScenarioConfig.h"

ScenarioConfig_001::ScenarioConfig_001(): ScenarioModel()
{
	m_pTileMapModel = new TileMapConfig_001();
}

ScenarioConfig_001::~ScenarioConfig_001()
{
	delete m_pTileMapModel;
}