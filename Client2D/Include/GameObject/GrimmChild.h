#pragma once

#include "GameObject\GameObject.h"

class CGrimmChild :
    public CGameObject
{
	friend class CScene;

protected:
	CGrimmChild();
	CGrimmChild(const CGrimmChild& Obj);
	virtual ~CGrimmChild();

private:
	CSharedPtr<class CSpriteComponent>	m_Sprite;
	CSharedPtr<class CColliderBox2D>	m_Body;
	CSharedPtr<class CGrimm>	m_Grimm;

private:
	Vector2	m_Move;
	int		m_MonsterDir;
	float	m_MoveSpeed;
	bool	m_EnableChase;
	Vector2	m_Pos;
	Vector2	m_PrevPos;
	float m_DelayTime;

private:
	std::vector<std::string>	m_vecSequenceKey[2];
	CSharedPtr<class CAnimation2D> m_Animation;


	CSharedPtr<class CSceneComponent>   m_UpdateComponent;

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);

public:
	void CollisionBegin(const CollisionResult& result);
	void CollisionEnd(const CollisionResult& result);
	virtual CGrimmChild* Clone()    const;
};

