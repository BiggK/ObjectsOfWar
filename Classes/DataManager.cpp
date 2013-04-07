#include "DataManager.h"

bool DataManager::SaveGame()
{
	CCUserDefault::sharedUserDefault()->setStringForKey("string1", GameDataModel::getInstance().GetPlayerName());
	LoadGame();
	return true;
}
bool DataManager::LoadGame()
{
	string ret = CCUserDefault::sharedUserDefault()->getStringForKey("string1");
    CCLOG("string is %s", ret.c_str());
	return true;
}