#ifndef __GAME_DATA_MODEL_H__
#define __GAME_DATA_MODEL_H__
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

//Stores the data for the current game.  Singleton object.
class GameDataModel
{
public:
	//Singleton!
    static GameDataModel& getInstance()
    {
        static GameDataModel	instance; // Guaranteed to be destroyed.
        return instance;
    }

	void init();
	const char* GetPlayerName(){return m_playerName;}
	void SetPlayerName(const char* playerName){m_playerName = playerName;}
private:
	//singleton stuff
	GameDataModel(void);
    GameDataModel(GameDataModel const&);			// Don't Implement
    void operator=(GameDataModel const&);	// Don't implement

	//member variables
	const char* m_playerName;
};

#endif