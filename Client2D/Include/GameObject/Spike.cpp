#include "Spike.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Resource/Material/Material.h"
#include "Animation/Animation2D.h"
#include "Input.h"
#include "Grimm.h"
#include "Scene/Scene.h"

CSpike::CSpike() :
	m_MiniOn(true),
	m_LongOn(false),
	m_Destroyed(false)
{
	SetTypeID<CSpike>();

	m_ObjectTypeName = "Spike";
}

CSpike::CSpike(const CSpike& Obj)
{
	m_Sprite = (CSpriteComponent*)FindComponent("sprite");
	m_Body = (CColliderBox2D*)FindComponent("Body");
}

CSpike::~CSpike()
{
}

void CSpike::SetCollisionProfileName(const std::string& Name)
{
	m_Body->SetCollisionProfile(Name);
}

void CSpike::Start()
{
	CGameObject::Start();

	m_Body = CreateComponent<CColliderBox2D>("Body");
	m_Body->SetCollisionProfile("Monster");
	m_Sprite = CreateComponent<CSpriteComponent>("Sprite");

	m_Body->AddChild(m_Sprite);
	m_Body->SetBoxSize(94.6f, 165.f);

	m_Body->SetCollisionCallback<CSpike>(ECollision_Result::Collision, this, &CSpike::CollisionBegin);
	m_Body->SetCollisionCallback<CSpike>(ECollision_Result::Collision, this, &CSpike::CollisionEnd);

	m_Sprite->SetPivot(0.5f, 0.5f);
	m_Sprite->SetRelativeScale(94.6f, 165.f);


	m_Animation = m_Sprite->SetAnimation<CAnimation2D>("Monster");

	m_Animation->AddAnimation("MiniSpike", "MiniSpike", 1.f, 1.f, false);
	m_Animation->AddAnimation("LongSpike", "LongSpike", 1.f, 0.7f, false);


	//CInput::GetInst()->AddBindFunction<CSpike>("Up", Input_Type::Down,
	//	this, &CSpike::Down, m_Scene);
}

bool CSpike::Init()
{
	CGameObject::Init();

	return true;
}

void CSpike::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);

	if(m_Scene)
		m_Grimm = (CGrimm*)m_Scene->FindObject("Grimm");

	//m_Body->AddWorldPositionX(-5.f);

	if (m_MiniOn)
	{
		m_Time += DeltaTime;

		m_Animation->ChangeAnimation("MiniSpike");
		m_Body->GetWorldPos().y;

		float PosY = m_Body->GetWorldPos().y;

		if (m_Time >= 1.8f)
		{
			m_LongOn = true;

			m_Animation->ChangeAnimation("LongSpike");

			m_Body->SetBoxSize(94.4f, 850.f);
			m_Sprite->SetRelativeScale(94.4f, 850.f);

			m_Body->SetWorldPositionY(550.f);
			float PosY = m_Body->GetWorldPos().y;

			m_Time = 0.f;

			m_MiniOn = false;
		}

		m_LongOn = false;

		PosY = m_Body->GetWorldPos().y;
	}

	m_Animation->SetCurrentEndFunction("LongSpike", this, &CSpike::Destroy);
}

void CSpike::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

CSpike* CSpike::Clone() const
{
	return  new CSpike(*this);
}

void CSpike::Destroy()
{
	m_Destroyed = true;
	CGameObject::Destroy();
	
}

void CSpike::CollisionBegin(const CollisionResult& result)
{
	// º® ÄÝ¸®ÀüÀÌ¶û ºÎµúÈ÷¸é »ç¶óÁö°Ô²û.
	// Destroy();
}

void CSpike::CollisionEnd(const CollisionResult& result)
{
}

void CSpike::Down()
{
	m_Body->AddWorldPositionY(-10.f);
}
