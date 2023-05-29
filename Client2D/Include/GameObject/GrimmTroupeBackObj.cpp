#include "GrimmTroupeBackObj.h"
#include "Component/SpriteComponent.h"
#include "Resource/Material/Material.h"

CGrimmTroupeBackObj::CGrimmTroupeBackObj()
{
	SetTypeID<CGrimmTroupeBackObj>();

	m_ObjectTypeName = "GrimmTroupeBackObj";
}

CGrimmTroupeBackObj::CGrimmTroupeBackObj(const CGrimmTroupeBackObj& Obj)
{
	m_Sprite = (CSpriteComponent*)FindComponent("sprite");
}

CGrimmTroupeBackObj::~CGrimmTroupeBackObj()
{
}

bool CGrimmTroupeBackObj::Init()
{
	CGameObject::Init();

	m_Sprite = CreateComponent<CSpriteComponent>("sprite");

	m_Sprite->GetMaterial(0)->SetShader("TileMapBackShader");
	m_Sprite->GetMaterial(0)->SetRenderState("DepthLessEqual");
	m_Sprite->SetTexture("Dirtmouth", TEXT("Dirtmouth.png"));
	m_Sprite->SetWorldScale(1920.f, 1080.f);
	m_Sprite->SetWorldPosition(0.f, 0.f);
	m_Sprite->SetPivot(0.f, 0.f);

    return true;
}

void CGrimmTroupeBackObj::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}
