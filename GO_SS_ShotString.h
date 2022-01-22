#pragma once
#include "GameObject.h"

class GO_SS_Player;
class GO_SS_Target;
#include "GO_SS_Scramble.h"

class GO_SS_ShotString :public GameObject
{
private:
	//テクスチャ用
	char TEX_NAME[64] = "data/TEXTURE/String1.png";
	int String_Texture;

	char CIRCLE_TEX_NAME[64] = "data/TEXTURE/circle1.png";
	int Circle_Texture;

	const FLOAT m_CircleSizeMax = 200.0f;
	const FLOAT m_DecreaseJump = 500.0f;
public:
	// GameObjectを介して継承されました
	virtual void Initialize		(void)	override;
	virtual void Finalize		(void)	override;
	virtual void Update			(void)	override;
	virtual void Draw			(void)	override;
	virtual int GetGameScene	(void)	override	{ return GAME_SCENE; }

	//ゲッター
	FLOAT GetAngle(void){ return String_Vertex.angle; }
	VERTEX_CIRCLE* GetCircle(void) { return &Circle_Vertex; }

	//セッター
	void SetPlayer(GO_SS_Player* p)	{ m_pPlayer = p; }
	void SetStringUse(bool flag) { String_Vertex.use = flag; }
	void SetTarget(GO_SS_Target* p)	{ m_pTarget = p; }
	void SetScramble(GO_SS_Scramble* p) { m_pScramble = p; }

	void SetPos(D3DXVECTOR2 pos)	{ String_Vertex.pos = pos; }
	void SetNatto(int index) { m_pScramble->SetNato(index); }

//public 変数

	bool m_LinerEnd = false;

	bool IsClickTarget = false;

	int IsInsideTarget = -1;

	int m_AimTarget = -1;

	FLOAT m_TimeDelay;

private:
	//ゲームシーン用
	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	//頂点パラメータ
	VERTEX_SHOOTSTIRNG	String_Vertex;
	VERTEX_CIRCLE		Circle_Vertex;

	//狙う位置
	D3DXVECTOR2 AimPos;

	GO_SS_Player* m_pPlayer;
	GO_SS_Target* m_pTarget;
	GO_SS_Scramble* m_pScramble;

	//ジャンプカウンター
	int m_jumpCounter = 0;

	bool m_AimFlag;

	

//メンバ関数
	
	//	ターゲットではない場所をクリック
	void NoTargetClick(void);

	//	ターゲットをクリックした
	void TargetClick(void);

	int TargetIsInRange(void);

	void ChangeAim(void);

	//	デバッグ用
	void DebugOut(void);

	//--糸の長さ伸ばす--//
	//	引数:伸ばす量	//
	//	max -> ターゲットとプレイヤーの距離	//
	void ExtendLengthOfString(FLOAT amount);

	//	カーソルとプライヤーの距離取得
	FLOAT GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2);

	//	プレイヤーとカーソルの角度取得
	FLOAT GetAnglePlayerAndCursor();

	//	円のサイズを変更する
	void ChangeSizeOfCircle();
};

