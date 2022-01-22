#include "GO_SS_NattoRotate.h"


GO_SS_NattoRotate::GO_SS_NattoRotate()
{
    for (int i = 0; i < NATTO_ROTATE_OBJECT_MAX; i++) {
        m_pNattoRotateObjects[i] = nullptr;
    }

    m_pNattoRotateObjects[0] = new NattoRotateObject("data/TEXTURE/�[��.png");
    m_pNattoRotateObjects[1] = new NRO_Natto("data/TEXTURE/Timer.png");
}

GO_SS_NattoRotate::~GO_SS_NattoRotate()
{
    for (int i = 0; i < NATTO_ROTATE_OBJECT_MAX; i++) {
        delete m_pNattoRotateObjects[i];
    }
}

void GO_SS_NattoRotate::Initialize(void)
{


    for (int i = 0; i < NATTO_ROTATE_OBJECT_MAX; i++) {
        if (!m_pNattoRotateObjects[i])continue;
        m_pNattoRotateObjects[i]->Initialize();
    }
}

void GO_SS_NattoRotate::Finalize(void)
{
    for (int i = 0; i < NATTO_ROTATE_OBJECT_MAX; i++) {
        if (!m_pNattoRotateObjects[i])continue;
        m_pNattoRotateObjects[i]->Finalize();
    }
}

void GO_SS_NattoRotate::Update(void)
{


    for (int i = 0; i < NATTO_ROTATE_OBJECT_MAX; i++) {
        if (!m_pNattoRotateObjects[i])continue;
        m_pNattoRotateObjects[i]->Update();
    }
}

void GO_SS_NattoRotate::Draw(void)
{


    for (int i = 0; i < NATTO_ROTATE_OBJECT_MAX; i++) {
        if (!m_pNattoRotateObjects[i])continue;
        m_pNattoRotateObjects[i]->Draw();
    }
}



int GO_SS_NattoRotate::GetGameScene(void)
{
    return GAMESCENE_GAME_TEST;
}

void GO_SS_NattoRotate::SetNatto(void)
{
    for (int i = 0; i < NATTO_ROTATE_OBJECT_MAX; i++) {
        if (!m_pNattoRotateObjects[i])continue;
        m_pNattoRotateObjects[i]->SetNatto();
    }
}

void GO_SS_NattoRotate::SetNatto(int index)
{
    if (!m_pNattoRotateObjects[index])return;
    m_pNattoRotateObjects[index]->SetNatto();
}

void GO_SS_NattoRotate::SetPos(D3DXVECTOR2 pos)
{
    for (int i = 0; i < NATTO_ROTATE_OBJECT_MAX; i++) {
        if (!m_pNattoRotateObjects[i])continue;
        m_pNattoRotateObjects[i]->SetPos(pos);
    }
}

