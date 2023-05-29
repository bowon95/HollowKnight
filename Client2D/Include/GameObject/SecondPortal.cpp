#include "SecondPortal.h"
#include "Player2D.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"
#include "../Scene/SecondSceneInfo.h"
#include "../Scene/DirtmouthSceneInfo.h"

CSecondPortal::CSecondPortal()
{
	SetTypeID<CSecondPortal>();

	m_ObjectTypeName = "SecondPortal";
}

CSecondPortal::CSecondPortal(const CSecondPortal& Obj)
{
	m_Body = (CColliderBox2D*)FindComponent("Body");
	m_Sprite = (CSpriteComponent*)FindComponent("sprite");
}

CSecondPortal::~CSecondPortal()
{
}

void CSecondPortal::Start()
{
	CGameObject::Start();

	m_Body = CreateComponent<CColliderBox2D>("SecondPortal");

	SetRootComponent(m_Body);

	m_Body->SetCollisionProfile("Portal");

	//m_Body->AddChild(m_Sprite);
	m_Body->SetPivot(0.5f, 0.5f);

	m_Body->SetBoxSize(100.f, 100.f);
	//m_Body->SetRelativeScale(15.f, 2.f);
	m_Body->SetWorldPosition(1886.f, 850.f);

	m_Body->SetCollisionCallback<CSecondPortal>(ECollision_Result::Collision, this, &CSecondPortal::Scene1CollisionBegin);
}

bool CSecondPortal::Init()
{
	CGameObject::Init();


	return true;
}

void CSecondPortal::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CSecondPortal::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

CSecondPortal* CSecondPortal::Clone() const
{
	return new CSecondPortal(*this);
}

void CSecondPortal::Scene1CollisionBegin(const CollisionResult& result)
{
	if (result.Dest->GetCollisionProfile()->Name == "Player")
	{
		CSceneManager::GetInst()->CreateNextScene(true);

		CSceneManager::GetInst()->CreateSceneInfo<CDirtmouthSceneInfo>(false);

		CSceneManager::GetInst()->GetNextScene()->Load("Dirtmouthreal.scn", SCENE_PATH);
	}
}

void CSecondPortal::Scene1CollisionEnd(const CollisionResult& result)
{
}

void CSecondPortal::Scene2CollisionBegin(const CollisionResult& result)
{
}

void CSecondPortal::Scene2CollisionEnd(const CollisionResult& result)
{
}
