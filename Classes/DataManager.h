#ifndef _DATA_MANAGER_H_
#define _DATA_MANAGER_H_
#include "cocos2d.h"
#include "GameDataModel.h"

using namespace cocos2d;

//Class that handles drawing of the map layer in a scenario.
class DataManager
{
public:
	DataManager(){};
    virtual ~DataManager();
	static bool SaveGame();
	static bool LoadGame();
protected:

};
#endif