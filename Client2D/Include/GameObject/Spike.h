#pragma once

#include "GameObject\GameObject.h"

class CSpike :
    public CGameObject
{
	friend class CScene;

protected:
	CSpike();
	CSpike(const CSpike& Obj);
	virtual ~CSpike();

private:
	CSharedPtr<class CSpriteComponent>	m_Sprite;
	CSharedPtr<class CColliderBox2D>	m_Body;
	CSharedPtr<class CAnimation2D> m_Animation;
	CSharedPtr<class CGrimm>	m_Grimm;
	CScene* m_Scene;

public:
	bool m_MiniOn;
	bool m_LongOn;
	bool m_Destroyed;
	float m_Time;

public:
	void SetCollisionProfileName(const std::string& Name);

public:
	bool	GetMiniOn()
	{
		return m_MiniOn;
	}

	bool	GetDestroyed()
	{
		return m_Destroyed;
	}

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Destroy();
	virtual CSpike* Clone()    const;

private:
	void CollisionBegin(const CollisionResult& result);
	void CollisionEnd(const CollisionResult& result);
	void Down();
};

