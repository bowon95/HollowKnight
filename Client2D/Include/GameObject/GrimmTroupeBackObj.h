#pragma once

#include "GameObject\GameObject.h"

class CGrimmTroupeBackObj :
    public CGameObject
{
	friend class CScene;

private:
	CSharedPtr<class CSpriteComponent>	m_Sprite;

protected:
	CGrimmTroupeBackObj();
	CGrimmTroupeBackObj(const CGrimmTroupeBackObj& Obj);
	virtual ~CGrimmTroupeBackObj();

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
};

