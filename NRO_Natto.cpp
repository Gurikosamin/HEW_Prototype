#include "NRO_Natto.h"

void NRO_Natto::Initialize(void)
{

    for (int i = 0; i < NATTO_MAX; i++) {
        //  D3DXVECTOR2
        m_Vertex[i].pos = D3DXVECTOR2(SCREEN_WIDTH / 4 * frand(), 100.0f * frand());
        m_Vertex[i].dpos = m_Vertex[i].pos;
        m_Vertex[i].size = D3DXVECTOR2(50.0f, 50.0);

        //  FLOAT
        m_Vertex[i].angle = 0.1f;
        m_Vertex[i].rot = frand_r();
        m_Vertex[i].alpha = 1.0f;
        m_Vertex[i].radius = frand() * 100.0f + 50.0f;

        //  bool
        m_Vertex[i].use = false;

    }

}

void NRO_Natto::Finalize(void)
{
    NattoRotateObject::Finalize();
}

void NRO_Natto::Update(void)
{
    NattoRotateObject::Update();
}

void NRO_Natto::Draw(void)
{
    /*DrawSprite(GetTexIndex(), SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 3*2, 
        100.0f, 100.0f,
        1.0f, 1.0f, 1.0f, 1.0f);*/

    NattoRotateObject::Draw();
}

int NRO_Natto::GetGameScene(void)
{
    return 0;
}
