#pragma once

#include "GameObject/GameObject.h"

class CSecondBackObj :

	public CGameObject
{
	friend class CScene;

private:
	CSharedPtr<class CSpriteComponent>	m_Sprite;

protected:
	CSecondBackObj();
	CSecondBackObj(const CSecondBackObj& Obj);
	virtual ~CSecondBackObj();

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
};