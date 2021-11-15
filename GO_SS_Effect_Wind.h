#pragma once
#include "GameObject.h"
class GO_SS_Effect_Wind :
    public GameObject
{
public:


    // GameObject ����Čp������܂���
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override { return GAME_SCENE; }

    void SetEffTrue(void) { windEff.use = true; }
    void SetEffFalse(void) { windEff.use = false; }
    

private:
    //�Q�[���V�[���p
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    //�e�N�X�`���p
    char TEX_NAME[64] = "data/TEXTURE/wind1.png";
    int Eff_Texture;

    VERTEX_EFF windEff;
};

