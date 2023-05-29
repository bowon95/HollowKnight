#include "GrimmLandPoint.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"
#include "../Scene/FirstSceneInfo.h"
#include "../Scene/SecondSceneInfo.h"

CGrimmLandPoint::CGrimmLandPoint()
{
	SetTypeID<CGrimmLandPoint>();

	m_ObjectTypeName = "GrimmLandPoint";
}

CGrimmLandPoint::CGrimmLandPoint(const CGrimmLandPoint& Obj)
{
	m_Body = (CColliderBox2D*)FindComponent("Body");
	m_Sprite = (CSpriteComponent*)FindComponent("sprite");
}

CGrimmLandPoint::~CGrimmLandPoint()
{
}

void CGrimmLandPoint::Start()
{
	CGameObject::Start();

	m_Body = CreateComponent<CColliderBox2D>("Body");

	SetRootComponent(m_Body);

	m_Body->SetCollisionProfile("Ground");
	 
	m_Body->SetPivot(0.5f, 0.5f);

	m_Body->SetBoxSize(1980.f, 100.f);
	m_Body->SetWorldPosition(990.f, 150.f);

	m_Body->SetCollisionCallback<CGrimmLandPoint>(ECollision_Result::Collision, this, &CGrimmLandPoint::CollisionBegin);
}

bool CGrimmLandPoint::Init()
{
	CGameObject::Init();


	return true;
}

void CGrimmLandPoint::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CGrimmLandPoint::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

CGrimmLandPoint* CGrimmLandPoint::Clone() const
{
	return new CGrimmLandPoint(*this);
}

void CGrimmLandPoint::CollisionBegin(const CollisionResult& result)
{
	/*if (result.Dest->GetCollisionProfile()->Name == "Grimm")
	{
	}*/
}

void CGrimmLandPoint::CollisionEnd(const CollisionResult& result)
{
}
