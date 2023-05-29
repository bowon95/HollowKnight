#pragma once

#include "GameObject/GameObject.h"

enum class EMonster_Animation
{
	Idle,
	Move,
	Attack,
	Dash,
	Land
};

class CMonster :
    public CGameObject
{
	friend class CScene;

protected:
	CMonster();
	CMonster(const CMonster& Obj);
	virtual ~CMonster();

private:
	CSharedPtr<class CSpriteComponent>	m_Sprite;
	CSharedPtr<class CColliderBox2D>	m_Body;
	CSharedPtr<class CColliderBox2D>	m_AccessRange;
	CSharedPtr<class CColliderBox2D>	m_DashRange;

private:
	Vector2	m_Move;
	int		m_MonsterDir;
	float	m_MoveSpeed;
	bool	m_EnableChase;
	int		m_HP;
	Vector2	m_Pos;
	Vector2	m_PrevPos;
	float	m_MoveRange;

private:
	std::vector<std::string>	m_vecSequenceKey[2];
	EMonster_Animation	m_PrevMonsterAnim;
	EMonster_Animation	m_MonsterAnim;
	CSharedPtr<class CAnimation2D> m_Animation;


	CSharedPtr<class CSceneComponent>   m_UpdateComponent;

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual float InflictDamage(float Damage);

public:
	void AccessRangeCollisionBegin(const CollisionResult& result);
	void AccessRangeCollisionEnd(const CollisionResult& result);
	void DashRangeCollisionBegin(const CollisionResult& result);
	void DashRangeCollisionEnd(const CollisionResult& result);
	void CollisionBegin(const CollisionResult& result);
	void CollisionEnd(const CollisionResult& result);
	virtual CMonster* Clone()    const;
};

