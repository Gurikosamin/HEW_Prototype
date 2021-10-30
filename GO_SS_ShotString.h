#pragma once
#include "GameObject.h"

class GO_SS_Player;

class GO_SS_ShotString :public GameObject
{
public:
	// GameObjectを介して継承されました
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;
	virtual int GetGameScene(void) override { return GAME_SCENE; }

	void SetPlayer(GO_SS_Player* p_player) { mp_player = p_player; }
	FLOAT GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2);

private:
	const int GAME_SCENE = GAMESCENE_GAME_TEST;
	char TEX_NAME[64] = "data/TEXTURE/String.png";
	int String_Texture;

	GO_SS_Player* mp_player;
	VERTEX_NOMAL player_Parameter;
	VERTEX_NOMAL String_Vertex;
	D3DXVECTOR2 CursorPos;
	float angle;
};