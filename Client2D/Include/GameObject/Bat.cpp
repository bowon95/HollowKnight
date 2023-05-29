#include "Bat.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Resource/Material/Material.h"
#include "Animation/Animation2D.h"
#include "Player2D.h"
#include "Grimm.h"
#include "Scene/Scene.h"


CBat::CBat()
{
	SetTypeID<CBat>();

	m_ObjectTypeName = "Bat";
}

CBat::CBat(const CBat& Obj)
{
	m_Sprite = (CSpriteComponent*)FindComponent("sprite");
	m_Body = (CColliderBox2D*)FindComponent("Body");
}

CBat::~CBat()
{
}

void CBat::SetCollisionProfileName(const std::string& Name)
{
	m_Body->SetCollisionProfile(Name);
}

void CBat::Start()
{
	CGameObject::Start();

	m_Body = CreateComponent<CColliderBox2D>("Body");
	m_Body->SetCollisionProfile("Monster");
	m_Sprite = CreateComponent<CSpriteComponent>("Sprite");

	m_Body->AddChild(m_Sprite);

	m_Body->SetCollisionCallback<CBat>(ECollision_Result::Collision, this, &CBat::CollisionBegin);
	m_Body->SetCollisionCallback<CBat>(ECollision_Result::Collision, this, &CBat::CollisionEnd);

	m_Body->SetBoxSize(172.f, 176.f);

	m_Sprite->SetPivot(0.5f, 0.5f);
	m_Sprite->SetRelativeScale(162.f, 166.f);

	m_Animation = m_Sprite->SetAnimation<CAnimation2D>("Monster");

	m_Animation->AddAnimation("GrimmFireLeft", "GrimmFireLeft", 1.f, 1.f, true);
	m_Animation->AddAnimation("GrimmFireRight", "GrimmFireRight", 1.f, 1.f, true);
}

bool CBat::Init()
{
	CGameObject::Init();

	return true;
}

void CBat::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);

	m_Grimm = (CGrimm*)m_Scene->FindObject("Grimm");

	if (m_Grimm->GetGrimmDir() == -1)
	{
		m_Animation->ChangeAnimation("GrimmFireLeft");
		AddWorldPositionX(-10.f);
	}

	else
	{
		m_Animation->ChangeAnimation("GrimmFireRight");
		AddWorldPositionX(10.f);
	}

	if (m_Body->GetWorldPos().x <= 0.f || m_Body->GetWorldPos().x > 1280)
		m_Body->Destroy();
	
}

void CBat::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

CBat* CBat::Clone() const
{
    return  new CBat(*this);
}

void CBat::CollisionBegin(const CollisionResult& result)
{
	if (result.Dest->GetCollisionProfile()->Name == "Player")
	{
		Destroy();
	}
}

void CBat::CollisionEnd(const CollisionResult& result)
{
}
