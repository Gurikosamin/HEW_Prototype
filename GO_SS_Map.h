#pragma once
#include "GameObject.h"
#include <iostream>
#include <vector>

class GO_SS_FileLoad;
class GO_SS_Wall;

//マップチップの列挙型
typedef enum{
	WALL_NUM =1,
}MAP_CHIP_NO;

class GO_SS_Map :public GameObject
{
public:
	// GameObject を介して継承されました
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;

	void SetFileLoad(GO_SS_FileLoad* p) { m_pFileLoad = p; }
	void SetWall(GO_SS_Wall* p) { m_pWall = p; }

	virtual int GetGameScene(void) override { return GAME_SCENE; }

	void ResetOnce(void) { once = true; }

private:
	int GAME_SCENE = GAMESCENE_GAME_TEST;	
	int MapData[STAGE_WALL_NUM_Y][STAGE_WALL_NUM_X];//まっぷでーた

	GO_SS_FileLoad* m_pFileLoad;	//FileLoadポインタ
	GO_SS_Wall* m_pWall;			//Wallポインタ

	MAP_CHIP_NO mapChipNo;

	bool once;

};