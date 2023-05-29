#pragma once

#include "GameObject/GameObject.h"

enum class EGrimm_Animation
{
	First_GrimmAppear, // (Start = Appear). Appear - GrimmIdle EndFunction���� �������.
	GrimmStretch,
	GrimmAbsorb1,
	GrimmAbsorb2,
	GrimmRoar,
	GrimmBomb,
	GrimmToSpike,
	GrimmSpike,
	GrimmToDive,
	GrimmDive,
	GrimmDash,
	GrimmCurtain,
	Disappear
};


/*
Start - GrimmIdle(2�� ��) - GrimmStretch��ġ��(��ġ�ڸ��� GrimmChild�� ����) - Grimm3(GrimmBack �� 2�� ��)  - 
GrimmIdle(2�� - �� ���̿� ���������� �����̶� �뷡)- Roar�Ҹ�����(3��)
*/

class CGrimm	:
	public CGameObject
{
	friend class CScene;

protected:
	CGrimm();
	CGrimm(const CGrimm& Obj);
	virtual ~CGrimm();

private:
	int m_Dir;
	float m_MoveSpeed;

private:
	std::vector<std::string>			m_vecSequenceKey[2];
	CSharedPtr<class CPlayer2D>			m_Player;
	CSharedPtr<class CGrimmChild>		m_GrimmChild;
	CSharedPtr<class CSpriteComponent>	m_Sprite;
	CSharedPtr<class CColliderOBB2D>	m_Body;
	CSharedPtr<class CWallComponent>	m_Wall;
	CSharedPtr<class CAnimation2D>		m_Animation;
	class CBullet* m_FireBalls[15];
	CSharedPtr<class CBat>				m_Bat;	
	CSharedPtr<class CSpike>	m_Spike[8];

	//class CScene* m_Scene;

private:
	EGrimm_Animation	m_GrimmAnim;
	float	m_LoadingTime;
	float	m_SpikeTime;
	float	m_DiveTime;
	bool	m_RoarOn;
	bool	m_FightOn;
	bool	m_DrawOn;
	bool	m_DashOn;

	// ���� ���� ������
private: 
	int		m_RandomNum;
	bool    m_GrimmBombOn;
	bool    m_GrimmSpikeOn;
	bool    m_GrimmToDiveOn;
	bool    m_GrimmCurtainOn;
	bool	m_GrimmDiveStartOn;
	bool	m_DashCollisionOn;
	int		m_CountBomb;
	int		m_CountSpawnBat;
	int		m_CountSpike;


public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual float InflictDamage(float Damage);

private:
	void CollisionBegin(const CollisionResult& result);
	void CollisionEnd(const CollisionResult& result);



private:
	void CheckAttack();
	void BeforeAttack();
	void DrawRandom();
	void GrimmBomb();
	void GrimmCurtain();
	void SpawnBat();
	void FireBalls();
	void DrawRandomOn();
	void Spike();
	void Dive();
	void DiveStart();
	void Dash();
	void Disappear();

public:
	int GetCountBomb()	const
	{
		return m_CountBomb;
	}

	int GetGrimmDir()	const
	{
		return m_Dir;
	}

	void SetGrimmSpikeOn(bool GrimmSpikeOn)
	{
		m_GrimmSpikeOn = GrimmSpikeOn;
	}

};