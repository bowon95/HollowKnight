#pragma once

#include "GameObject/GameObject.h"

class CBullet :
    public CGameObject
{
	friend class CScene;

protected:
	CBullet();
	CBullet(const CBullet& Obj);
	virtual ~CBullet();

private:
	CSharedPtr<class CSpriteComponent>	m_Sprite;
	CSharedPtr<class CColliderSphere2D>	m_Body;
	CSharedPtr<class CAnimation2D> m_Animation;

private:
	Vector3 m_Dir;

public:
	void SetCollisionProfileName(const std::string& Name);

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual CBullet* Clone()    const;

private:
	void CollisionBullet(const CollisionResult& result);
};

