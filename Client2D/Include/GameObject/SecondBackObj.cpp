#include "SecondBackObj.h"
#include "Component/SpriteComponent.h"
#include "Resource/Material/Material.h"

CSecondBackObj::CSecondBackObj()
{
	SetTypeID<CSecondBackObj>();

	m_ObjectTypeName = "SecondBackObj";
}

CSecondBackObj::CSecondBackObj(const CSecondBackObj& Obj)
{
	m_Sprite = (CSpriteComponent*)FindComponent("sprite");
}

CSecondBackObj::~CSecondBackObj()
{
}

bool CSecondBackObj::Init()
{
	CGameObject::Init();

	m_Sprite = CreateComponent<CSpriteComponent>("sprite");
	m_Sprite->GetMaterial(0)->SetShader("TileMapBackShader");
	m_Sprite->GetMaterial(0)->SetRenderState("DepthLessEqual");
	m_Sprite->SetTexture("Crossroads2", TEXT("Crossroads2.png"));
	m_Sprite->SetWorldScale(1920.f, 1080.f);
	m_Sprite->SetWorldPosition(0.f, 0.f);
	m_Sprite->SetPivot(0.f, 0.f);

	return true;
}

void CSecondBackObj::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

