#pragma once

#include "GameObject\GameObject.h"

class CBat :
    public CGameObject
{
	friend class CScene;

protected:
	CBat();
	CBat(const CBat& Obj);
	virtual ~CBat();

private:
	CSharedPtr<class CSpriteComponent>	m_Sprite;
	CSharedPtr<class CColliderBox2D>	m_Body;
	CSharedPtr<class CAnimation2D> m_Animation;
	CSharedPtr<class CGrimm>	m_Grimm;

public:
	void SetCollisionProfileName(const std::string& Name);

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual CBat* Clone()    const;

private:
	void CollisionBegin(const CollisionResult& result);
	void CollisionEnd(const CollisionResult& result);
};

