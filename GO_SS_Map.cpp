#include "GO_SS_Map.h"
#include "GO_SS_FileLoad.h"
#include "GO_SS_Wall.h"

void GO_SS_Map::Initialize(void)
{
	m_pFileLoad->MapFileLoad(MapData);

	once = true;
}

void GO_SS_Map::Finalize(void)
{
}

void GO_SS_Map::Update(void)
{
	if (once == false)return;
	once = false;

	//�Ǖ`��
	for (int y = 0; y < WALL_NUM_Y; y++)
	{
		for (int x = 0; x < WALL_NUM_X; x++)
		{
			switch (MapData[y][x])
			{
			case WALL_NUM:
				m_pWall->SetWall(D3DXVECTOR2(WALL_WIDTH * x, WALL_HEIGHT * y), D3DXVECTOR2(WALL_WIDTH, WALL_HEIGHT));
				break;
			}
		}
	}
}

void GO_SS_Map::Draw(void)
{
	
}