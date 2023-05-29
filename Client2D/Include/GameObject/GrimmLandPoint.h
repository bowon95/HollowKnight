#pragma once

#include "GameObject\GameObject.h"

class CGrimmLandPoint :
	public CGameObject
{
	friend class CScene;

protected:
	CGrimmLandPoint();
	CGrimmLandPoint(const CGrimmLandPoint& Obj);
	virtual ~CGrimmLandPoint();

private:
	CSharedPtr<class CSpriteComponent>	m_Sprite;
	CSharedPtr<class CColliderBox2D>	m_Body;

public:
	void CollisionBegin(const CollisionResult& result);
	void CollisionEnd(const CollisionResult& result);

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual CGrimmLandPoint* Clone()    const;

};
