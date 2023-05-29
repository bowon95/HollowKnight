#include "Elderbug.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Resource/Material/Material.h"
#include "Animation/Animation2D.h"


CElderbug::CElderbug() 
{
	SetTypeID<CElderbug>();

	m_ObjectTypeName = "Elderbug";
}

CElderbug::CElderbug(const CElderbug& Obj)
{
	m_Sprite = (CSpriteComponent*)FindComponent("sprite");
	m_Body = (CColliderBox2D*)FindComponent("Body");
	m_Range = (CColliderBox2D*)FindComponent("Range");
}

CElderbug::~CElderbug()
{
}

void CElderbug::SetCollisionProfileName(const std::string& Name)
{
	m_Body->SetCollisionProfile(Name);
}

void CElderbug::Start()
{
	CGameObject::Start();

	m_Body = CreateComponent<CColliderBox2D>("Body");

	m_Body->SetCollisionProfile("NPC");

	m_Sprite = CreateComponent<CSpriteComponent>("sprite");

	m_Range = CreateComponent<CColliderBox2D>("Range");

	m_Body->AddChild(m_Sprite);
	m_Body->AddChild(m_Range);

	m_Body->SetWorldPosition(1384.f, 290.f);
	m_Body->SetBoxSize(124.f, 172.f);

	m_Range->SetCollisionCallback<CElderbug>(ECollision_Result::Collision, this, &CElderbug::CollisionBegin);
	m_Range->SetCollisionCallback<CElderbug>(ECollision_Result::Collision, this, &CElderbug::CollisionEnd);

	m_Sprite->SetPivot(0.5f, 0.5f);
	m_Sprite->SetRelativeScale(124.f, 172.f);

	m_Range->SetPivot(0.5f, 0.5f);
	m_Range->SetRelativeScale(5.f, 5.f);

	m_Animation = m_Sprite->SetAnimation<CAnimation2D>("Elderbug");

	m_Animation->AddAnimation("ElderbugIdle", "ElderbugIdle", 1.f, 0.7f, true);
	m_Animation->AddAnimation("ElderbugBye", "ElderbugBye", 1.f, 0.7f, false);

	m_Animation->SetCurrentAnimation("ElderbugBye");

}

bool CElderbug::Init()
{
	CGameObject::Init();


	return true;
}

void CElderbug::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CElderbug::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

CElderbug* CElderbug::Clone() const
{
	return  new CElderbug(*this);
}

void CElderbug::CollisionBegin(const CollisionResult& result)
{
	// º® ÄÝ¸®ÀüÀÌ¶û ºÎµúÈ÷¸é »ç¶óÁö°Ô²û.
	// Destroy();
	if (result.Dest->GetCollisionProfile()->Name == "Player")
	{
		m_Animation->ChangeAnimation("ElderbugBye");
	}
}

void CElderbug::CollisionEnd(const CollisionResult& result)
{
}