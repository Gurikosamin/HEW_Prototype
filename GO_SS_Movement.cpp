#include "GO_SS_Movement.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"
#include "GO_SS_Wall.h"
#include "GO_SS_Map.h"
#include "GO_SS_Effect_Wind.h"

#include <cmath>

void GO_SS_Movement::Update(void)
{

	/*	�v���C���[�̋���	-> �؂�ւ�(PlayerMove�@index)
		PLAYERMOVE_LINEAR,
		PLAYERMOVE_CURVE,	
		PLAYERMOVE_PENDULUM,
	*/
	PlayerMoveSwitch(PLAYERMOVE_LINEAR);
	
	//�����蔻��̍X�V����
	m_ssCollision.CollisionUpdate();
	
	//�ޗ�����̕���
	FromAbyss();
}


//-----------------------------------------------------------------------------------------
//	JumpMove_Liner()
//-----------------------------------------------------------------------------------------
//	�����I�ȓ���
//	�^�[�Q�b�g�܂Œ��Ō�����
//-----------------------------------------------------------------------------------------
void GO_SS_Movement::JumpMove_Liner()
{
	//�����o������
	if (!m_pShotString->IsClickTarget)return;
	//if (!m_pShotString->IsCollTarget)return;

	//�d�̓��Z�b�g
	m_pPlayer->SetGravityDefault();

	//�v���C���[�Ǝ��̊p�x�擾
	FLOAT angle = m_pShotString->GetAngle();

	//�v���C���[��Y���@�����@
	m_pPlayer->AddYPos(-sinf(angle) * 25.0f);

	//�w�i�X�N���[������
	m_pBackGround->SubU(cosf(angle)/100.0f);


	m_pWall->AddX(-10.0f);

	m_pTarget->AddPosX(-10.0f);

	m_pEffectWind->SetEffTrue();
}

//-----------------------------------------------------------------------------------------
//	JumpMove_Curve()
//-----------------------------------------------------------------------------------------
//	�v���g�^�C�v�̂Ƃ��̓���
//-----------------------------------------------------------------------------------------
void GO_SS_Movement::JumpMove_Curve()
{
	//�����o������
	if (!m_pShotString->IsClickTarget)return;

	//�J�E���^�[������ɒB������
	if (JumpCounter >= JumpCountMax) {
		//�d�̓��Z�b�g
		m_pPlayer->SetGravityDefault();

		//�V���b�g�X�g�����O�̃N���b�N�t���O���낷
		m_pShotString->IsClickTarget = false;

		//�W�����v�J�E���^�[���Z�b�g
		JumpCounter = 0;
	}
	else {
		//�w�i�X�N���[������
		m_pBackGround->SubU(cosf(m_pShotString->GetAngle()) / 100.0f);


		m_pWall->AddX(cosf(m_pShotString->GetAngle())*10.0f);

		FLOAT angle = m_pShotString->GetAngle() * (FLOAT)180.0f / (FLOAT)PI;

		//�v���C���[�̓�������
		//		  90
		//				
		//	0			��180,��-180
		//				
		//		 -90
		//����̉E�������𔻒�
		if (angle >= 90 && angle < 180
			|| angle >= -180 && angle < -90) {

			m_pPlayer->WavePosPlus((float)(JumpCounter)*RADIAN);
		}
		else {
			m_pPlayer->WavePosMinus((float)(JumpCounter) * RADIAN );
		}
		

	
		//�J�E���^�[
		JumpCounter++;
	}

	//�W�����v���̍ŏ���1�񂾂�
	if (JumpCounter <= 1) {

		//�W�����v�̃t���[��������
		JumpCountMax = (int)(fabs(cosf(m_pShotString->GetAngle())* 60.0f));
	}
}

//-----------------------------------------------------------------------------------------
//	JumpMove_Pendulum()
//-----------------------------------------------------------------------------------------
//	�U��q�̂悤�ȓ���
//	���ɓ����Ă���A��ɏオ��
//-----------------------------------------------------------------------------------------
void GO_SS_Movement::JumpMove_Pendulum()
{
}

void GO_SS_Movement::PlayerMoveSwitch(PlayerMove index)
{
	//�v���C���[�̓����[���؂�ւ��\
	switch (index)
	{
	case PLAYERMOVE_NONE:
		break;
	case PLAYERMOVE_LINEAR:
		JumpMove_Liner();
		break;
	case PLAYERMOVE_CURVE:
		JumpMove_Curve();
		break;
	case PLAYERMOVE_PENDULUM:
		JumpMove_Pendulum();
		break;
	case PLAYERMOVE_MAX:
		break;
	default:
		break;
	}
}

void GO_SS_Movement::FromAbyss()
{
	if (m_pPlayer->GetPos().y >= SCREEN_HEIGHT) {
		m_pPlayer->SetPosY(0.0f);
		m_pTarget->ResetOnce();
		m_pWall->ResetOnce();
		m_pMap->ResetOnce();
	}
}





