#pragma once
#include "GameObject.h"

class GO_SS_Player;
class GO_SS_Target;

class GO_SS_ShotString :public GameObject
{
public:
	// GameObject����Čp������܂���
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;
	virtual int GetGameScene(void) override { return GAME_SCENE; }

	//�Q�b�^�[
	FLOAT GetAngle(void) { return String_Vertex.angle; }

	//�Z�b�^�[
	void SetPlayer(GO_SS_Player* p) { m_pPlayer = p; }
	void SetTarget(GO_SS_Target* p) { m_pTarget = p; }

	//public �ϐ�
	bool IsClick = false;

	bool IsClickTarget = false;

	bool IsInsideTarget = false;

	bool IsCollTarget = false;

private:
	//�Q�[���V�[���p
	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	//�e�N�X�`���p
	char TEX_NAME[64] = "data/TEXTURE/String1.png";
	int String_Texture;

	//���_�p�����[�^
	VERTEX_SHOOTSTIRNG String_Vertex;

	//����p
	D3DXVECTOR2 Coordinate[4];

	//�J�[�\���|�W�V����
	D3DXVECTOR2 CursorPos;
	
	//�J�[�\���ƃv���C���[�̋����擾
	FLOAT GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2);

	//�f�o�b�O�p
	void DebugOut(void);

	GO_SS_Player* m_pPlayer;
	GO_SS_Target* m_pTarget;

	//�W�����v�J�E���^�[
	int m_jumpCounter = 0;

//�����o�֐�
	
	//�^�[�Q�b�g�ł͂Ȃ��ꏊ���N���b�N
	void NoTargetClick(void);

	//�^�[�Q�b�g���N���b�N����
	void TargetClick(void);

	bool IsMouseInsideTarget(void);

	bool IsStringConnectTarget();


	//���̒��_���W��Coordinate�ɃZ�b�g
	void SetCoord(D3DXVECTOR2 pos, D3DXVECTOR2 size, FLOAT tx, FLOAT ty, FLOAT tw, FLOAT th, FLOAT angle);

};