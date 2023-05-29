#include "GrimmChild.h"
#include "Player2D.h"
#include "Grimm.h"
#include "Effect.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Component/ColliderSphere2D.h"
#include "Component/ColliderOBB2D.h"
#include "Component/Collider.h"
#include "Component/NavigationAgent.h"
#include "Resource/Material/Material.h"
#include "Scene/Scene.h"

CGrimmChild::CGrimmChild()	: m_DelayTime(0.f)
{
	SetTypeID<CGrimmChild>();

	m_ObjectTypeName = "GrimmChild";
}

CGrimmChild::CGrimmChild(const CGrimmChild& Obj)
{
	m_Body = (CColliderBox2D*)FindComponent("Body");
	m_Sprite = (CSpriteComponent*)FindComponent("sprite");
}

CGrimmChild::~CGrimmChild()
{
}

void CGrimmChild::Start()
{
	CGameObject::Start();

	m_Body = CreateComponent<CColliderBox2D>("Body");

	SetRootComponent(m_Body);

	m_Body->SetCollisionProfile("GrimmChild");

	m_Body->AddChild(m_Sprite);
	m_Body->SetBoxSize(87.f,79.f);
	m_Body->SetPivot(0.5f, 0.5f);


	/*if (m_Scene->FindObject("Player2D"))
	{
		Vector3 PlayerPos = m_Scene->FindObject("Player2D")->GetWorldPos();

		m_Body->SetWorldPosition(PlayerPos + Vector3(-100.f, 200.f, 0.f));

	}

	else*/
	m_Body->SetWorldPosition(100.f, 500.f);

	m_Sprite->SetPivot(0.5f, 0.5f);
	m_Sprite->SetRelativeScale(87.f, 79.f);
	m_Sprite->SetRelativePosition(0.f, 0.f);

	m_Body->SetCollisionCallback<CGrimmChild>(ECollision_Result::Collision, this, &CGrimmChild::CollisionBegin);
	m_Body->SetCollisionCallback<CGrimmChild>(ECollision_Result::Release, this, &CGrimmChild::CollisionEnd);

	m_Animation = m_Sprite->SetAnimation<CAnimation2D>("Monster");

	m_Animation->AddAnimation("GrimmChildLeft", "GrimmChildLeft", 1.f, 1.f, true);
	m_Animation->AddAnimation("GrimmChildRight", "GrimmChildRight", 1.f, 1.f, true);

	m_Animation->SetCurrentAnimation("GrimmChildRight");
}

bool CGrimmChild::Init()
{
	CGameObject::Init();

	m_Sprite = CreateComponent<CSpriteComponent>("sprite");

    return true;
}

void CGrimmChild::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);

	//if (m_Scene->FindObject("Player2D"))
	//{
	//	Vector3 GrimmChildPos = m_Body->GetWorldPos();

	//	Vector3 PlayerPos = m_Scene->FindObject("Player2D")->GetWorldPos();

	//	Vector3 Dir = (PlayerPos - GrimmChildPos) + Vector3(-90.f, 100.f, 0.f); // 해당 범위에 닿으면 멈추기

	//	Dir.Normalize();

	//	m_Body->AddWorldPosition(Dir * 100.f * g_DeltaTime);

	//}

	if (m_Scene->FindObject("Grimm"))
	{


		Vector3 GrimmChildPos = m_Body->GetWorldPos();
		Vector3 m_Grimm = m_Scene->FindObject("Grimm")->GetWorldPos();

		Vector3 Dir = (m_Grimm - GrimmChildPos);

		Dir.Normalize();

		//80
		m_Body->AddWorldPosition(Dir * 120.f * g_DeltaTime);

		m_DelayTime = 0;
	}
		
}

void CGrimmChild::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);

	
}

void CGrimmChild::CollisionBegin(const CollisionResult& result)
{
	if (result.Dest->GetCollisionProfile()->Name == "Monster")
	{
		m_Body->Destroy();
	}
}

void CGrimmChild::CollisionEnd(const CollisionResult& result)
{
}

CGrimmChild* CGrimmChild::Clone() const
{
	return new CGrimmChild(*this);
}
