#pragma once

#include "GameObject\GameObject.h"

class CElderbug :
    public CGameObject
{
	friend class CScene;

protected:
	CElderbug();
	CElderbug(const CElderbug& Obj);
	virtual ~CElderbug();

private:
	CSharedPtr<class CSpriteComponent>	m_Sprite;
	CSharedPtr<class CColliderBox2D>	m_Body;
	CSharedPtr<class CColliderBox2D>	m_Range;
	CSharedPtr<class CAnimation2D> m_Animation;

public:
	void SetCollisionProfileName(const std::string& Name);

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual CElderbug* Clone()    const;

private:
	void CollisionBegin(const CollisionResult& result);
	void CollisionEnd(const CollisionResult& result);
};

