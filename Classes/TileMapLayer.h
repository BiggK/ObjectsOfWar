#ifndef _TILE_MAP_LAYER_H_
#define _TILE_MAP_LAYER_H_
#include "cocos2d.h"
#include "TileMapConfig.h"
#include "TileMapModel.h"

using namespace cocos2d;

//Class that handles drawing of the map layer in a scenario.
class TileMapLayer : public cocos2d::CCLayerColor , public CCTargetedTouchDelegate
{
public:
    TileMapLayer();
    virtual ~TileMapLayer();
	bool init();
	void onExit();
	bool LoadModel(TileMapModel* tileMapModel);
	CREATE_FUNC(TileMapLayer);
protected:
	cocos2d::CCTMXTiledMap* m_pTileMap;
	cocos2d::CCTMXLayer* m_pBackgroundLayer;
	cocos2d::CCTMXLayer* m_pForegroundLayer;
	cocos2d::CCTMXLayer* m_pMetaLayer;
	TileMapModel* m_pTileMapModel;
};

#endif // _MAP_LAYER_H_