//---------------------------------------------
//	�I�u�W�F�N�g�ԒʐM�������ł��	[GO_SS_Movement.h]	
//                          Author: Yanagisawa
//---------------------------------------------
// GameSceneTest�̃I�u�W�F�N�g�iGO_SS_Manager�ɂ���|�C���^�j��
// �����Ŏg���āA�l�������荇��
//  
// �������g�����̃I�u�W�F�N�g�̏�������K�v���Ȃ��B
//      
// �������������ׂĂ�m���Ă���
//
//---------------------------------------------
#include "GameObject.h"
#include "GO_SS_Collision.h"

class GO_SS_BackGround;
class GO_SS_Player;
class GO_SS_Wall;
class GO_SS_ShotString;
class GO_SS_Target;
class GO_SS_Map;
class GO_SS_Effect_Wind;

enum PlayerMove {
    PLAYERMOVE_NONE,
    PLAYERMOVE_LINEAR,
    PLAYERMOVE_CURVE,
    PLAYERMOVE_PENDULUM,
    PLAYERMOVE_MAX,
};

class GO_SS_Movement :
    public GameObject
{
public:
    // GameObject ����Čp������܂���
    virtual void Initialize(void) override {};
    virtual void Finalize(void) override {};
    virtual void Update(void) override;
    virtual void Draw(void) override {};
    virtual int GetGameScene(void) override { return GAME_SCENE; }

    //�Z�b�^�[
    void SetBackGround(GO_SS_BackGround* p_BackGround) {
        m_pBackGround = p_BackGround;
        m_ssCollision.SetBackGround(p_BackGround);
    }
    void SetPlayer(GO_SS_Player* p_Player) { 
        m_pPlayer = p_Player; 
        m_ssCollision.SetPlayer(p_Player);
    }
    void SetWall(GO_SS_Wall* pWall) { 
        m_pWall = pWall; 
        m_ssCollision.SetWall(pWall);
    }
    void SetShotString(GO_SS_ShotString* p) { 
        m_pShotString = p; 
        m_ssCollision.SetShotString(p);
    }
    void SetTarget(GO_SS_Target* pTarget) {
        m_pTarget = pTarget; 
        m_ssCollision.SetTarget(pTarget);
    }
    void SetMap(GO_SS_Map* p) { m_pMap = p; }
    void SetEffWind(GO_SS_Effect_Wind* p) { m_pEffectWind = p; }
    
private:
    //�Q�[���V�[��
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    GO_SS_BackGround* m_pBackGround;
    GO_SS_Player* m_pPlayer;
    GO_SS_Wall* m_pWall;
    GO_SS_ShotString* m_pShotString;
    GO_SS_Target* m_pTarget;
    GO_SS_Map* m_pMap;
    GO_SS_Effect_Wind* m_pEffectWind;

    //�����o�ϐ�
    int JumpCounter = 0;
    int JumpCountMax = 60;

    GO_SS_Collision m_ssCollision;      //�����蔻����i���

//�����o�֐�

//-----------------------------------------------------------------------------------------
//	JumpMove_Liner()
//-----------------------------------------------------------------------------------------
//	�����I�ȓ���
//	�^�[�Q�b�g�܂Œ��Ō�����
//-----------------------------------------------------------------------------------------
    void JumpMove_Liner();

//-----------------------------------------------------------------------------------------
//	JumpMove_Curve()
//-----------------------------------------------------------------------------------------
//	�v���g�^�C�v�̂Ƃ��̓���
//-----------------------------------------------------------------------------------------
    void JumpMove_Curve();

//-----------------------------------------------------------------------------------------
//	JumpMove_Pendulum()
//-----------------------------------------------------------------------------------------
//	�U��q�̂悤�ȓ���
//	���ɓ����Ă���A��ɏオ��
//-----------------------------------------------------------------------------------------
    void JumpMove_Pendulum();

//-----------------------------------------------------------------------------------------
//    PlayerMoveSwitch(PlayerMove index);
//-----------------------------------------------------------------------------------------
//	�v���C���[�̋���	-> �؂�ւ�(PlayerMove�@index)
//    PLAYERMOVE_LINEAR,
//    PLAYERMOVE_CURVE,
//    PLAYERMOVE_PENDULUM,
//-----------------------------------------------------------------------------------------
    void PlayerMoveSwitch(PlayerMove index);


    void FromAbyss();

   
};


