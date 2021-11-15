#pragma once
#include "GameObject.h"

class GO_SS_Player;

class GO_SS_Scramble :
    public GameObject
{
public:
    // GameObject ����Čp������܂���
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override { return m_GameScene; }

    void SetPlayer(GO_SS_Player* p) { m_pPlayer = p; };

    void SetScrambleAngle(float angle) { Vortex_Vertex.angle = angle; }

    D3DXVECTOR2 GetScramblePos(){return Vortex_Vertex.pos;}

private:
    char TEX_NAME[128] = "data/TEXTURE/Vortex.png";

    int Scramble_texture;

    const int m_GameScene = GAMESCENE_GAME_TEST;

    bool scrambleflag;

    GO_SS_Player* m_pPlayer;

    VERTEX_A Vortex_Vertex;

    D3DXVECTOR2 playerPos;
};

