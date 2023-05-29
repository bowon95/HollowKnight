
#include "Monster.h"
#include "Player2D.h"
#include "Effect.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Component/ColliderSphere2D.h"
#include "Component/ColliderOBB2D.h"
#include "Component/Collider.h"
#include "Component/NavigationAgent.h"
#include "Resource/Material/Material.h"
#include "Scene/Scene.h"

CMonster::CMonster()	:
		m_Move(0.f, 0.f),
		m_MonsterDir(1),
		m_MoveSpeed(5),
		m_EnableChase(false),
		m_HP(15),
		m_Pos(0.f, 0.f),
		m_PrevPos(0.f, 0.f),
		m_MoveRange(10.f)
{
	SetTypeID<CMonster>();

	m_ObjectTypeName = "Monster";

	m_MonsterAnim = EMonster_Animation::Idle;
	m_PrevMonsterAnim = EMonster_Animation::Idle;
}

CMonster::CMonster(const CMonster& Obj) :
	CGameObject(Obj)
{
	m_Body = (CColliderBox2D*)FindComponent("Body");
	m_Sprite = (CSpriteComponent*)FindComponent("sprite");
	m_AccessRange = (CColliderBox2D*)FindComponent("Access");
	m_DashRange = (CColliderBox2D*)FindComponent("Dash");
}

CMonster::~CMonster()
{
}

void CMonster::Start()
{
	CGameObject::Start();

	m_Body = CreateComponent<CColliderBox2D>("Body"); 
	m_AccessRange = CreateComponent<CColliderBox2D>("Access");
	m_DashRange = CreateComponent<CColliderBox2D>("Dash");

	SetRootComponent(m_Body);

	m_Body->SetCollisionProfile("Monster");
	m_Body->AddChild(m_Sprite);
	m_Body->AddChild(m_AccessRange);
	m_Body->AddChild(m_DashRange);
	m_Body->SetWorldPosition(2000.f, 300.f);
	m_Body->SetPivot(0.5f, 0.5f);

	m_Sprite->SetPivot(0.5f, 0.f);
	m_Sprite->SetRelativeScale(100.f, 100.f);
	m_Sprite->SetRelativePosition(0.f, -50.f);

	m_AccessRange->SetCollisionProfile("MonsterRange");
	m_AccessRange->SetPivot(0.f, 0.f);
	m_AccessRange->SetRelativeScale(7.f, 1.f);
	m_AccessRange->SetRelativePosition(0.f, 1.f);

	m_DashRange->SetCollisionProfile("MonsterRange");
	m_DashRange->SetPivot(0.f, 0.f);
	m_DashRange->SetRelativeScale(5.f, 1.f);
	m_DashRange->SetRelativePosition(0.f, 0.f);
	

	m_Body->SetCollisionCallback<CMonster>(ECollision_Result::Collision, this, &CMonster::CollisionBegin); 
	m_Body->SetCollisionCallback<CMonster>(ECollision_Result::Release, this, &CMonster::CollisionEnd);

	m_AccessRange->SetCollisionCallback<CMonster>(ECollision_Result::Collision, this, &CMonster::AccessRangeCollisionBegin);
	m_AccessRange->SetCollisionCallback<CMonster>(ECollision_Result::Release, this, &CMonster::AccessRangeCollisionEnd);

	m_DashRange->SetCollisionCallback<CMonster>(ECollision_Result::Collision, this, &CMonster::DashRangeCollisionBegin);
	m_DashRange->SetCollisionCallback<CMonster>(ECollision_Result::Release, this, &CMonster::DashRangeCollisionEnd);

	int	AnimDirectionIndex = 0;

	if (m_MonsterDir == -1)
		AnimDirectionIndex = 1;

	m_Animation = m_Sprite->SetAnimation<CAnimation2D>("Monster");
	
	m_Animation->AddAnimation("MonsterIdleLeft", "MonsterIdleLeft", 1.f, 1.f, true);
	m_Animation->AddAnimation("MonsterIdleRight", "MonsterIdleRight", 1.f, 1.f, true, true);
	m_Animation->AddAnimation("MonsterLeft", "MonsterLeft", 1.f, 1.f, true);
	m_Animation->AddAnimation("MonsterRight", "MonsterRight", 1.f, 1.f, true, true);
	m_Animation->AddAnimation("MonsterAttackLeft", "MonsterAttackLeft", 1.f, 1.f, true);
	m_Animation->AddAnimation("MonsterAttackRight", "MonsterAttackRight", 1.f, 1.f, true, true);
	m_Animation->AddAnimation("MonsterDashLeft", "MonsterDashLeft", 1.f, 1.f, true);
	m_Animation->AddAnimation("MonsterDashRight", "MonsterDashRight", 1.f, 1.f, true, true);
	m_Animation->AddAnimation("MonsterLandLeft", "MonsterLandLeft", 1.f, 1.f, true);
	m_Animation->AddAnimation("MonsterLandRight", "MonsterLandRight", 1.f, 1.f, true, true);


	m_vecSequenceKey[0].push_back("MonsterIdleLeft");
	m_vecSequenceKey[0].push_back("MonsterLeft");
	m_vecSequenceKey[0].push_back("MonsterAttackLeft");
	m_vecSequenceKey[0].push_back("MonsterDashLeft");
	m_vecSequenceKey[0].push_back("MonsterLandLeft");

	m_vecSequenceKey[1].push_back("MonsterIdleRight");
	m_vecSequenceKey[1].push_back("MonsterRight");
	m_vecSequenceKey[1].push_back("MonsterAttackRight");
	m_vecSequenceKey[1].push_back("MonsterDashRight");
	m_vecSequenceKey[1].push_back("MonsterLandRight");

	m_Pos = m_Body->GetWorldPos();

}

bool CMonster::Init()
{
	CGameObject::Init();

	m_Sprite = CreateComponent<CSpriteComponent>("sprite");

	m_MonsterDir = -1;

	return true;
}

void CMonster::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
	// Move
	Vector3 PosX = m_Body->GetWorldAxis(AXIS_X) * -50.f * g_DeltaTime;
	m_Body->AddWorldPosition(PosX);


	//// 몬스터 범위 이동
	m_Body->AddWorldPositionX(-1.f);

	//m_Pos.x = GetWorldPos().x;
	//
	//Vector2 Pivot = GetPivot();
	//Vector2 Size = GetWorldScale();

	//if (m_Pos.x + (1.f - Pivot.x) * Size.x >= m_MoveRange)
	//{
	//	m_Pos.x = Pivot.x - (1.f - Pivot.x) * Size.x;
	//	m_MonsterDir *= -1;
	//}

	//else if (m_Pos.x - Pivot.x * Size.x <= -m_MoveRange)
	//{
	//	m_Pos.x = Pivot.x * Size.y;
	//	m_MonsterDir = -1;
	//}

	m_Pos = m_Body->GetWorldPos();

	m_Move.x = m_Pos.x - m_PrevPos.x;

	if (m_Move.x != 0)
	{
		if (m_Move.x < 0)
			m_MonsterDir = 1;

		else
			m_MonsterDir = -1;
	}

	int	AnimDirectionIndex = 0;

	if (m_MonsterDir == -1)
		AnimDirectionIndex = 1;

	switch (m_MonsterAnim)
	{
	case EMonster_Animation::Idle:
		m_Animation->ChangeAnimation(m_vecSequenceKey[AnimDirectionIndex][0]);
		break;
	case EMonster_Animation::Move:
		m_Animation->ChangeAnimation(m_vecSequenceKey[AnimDirectionIndex][1]);
		break;
	case EMonster_Animation::Attack:
		m_Animation->ChangeAnimation(m_vecSequenceKey[AnimDirectionIndex][2]);
		break;
	case EMonster_Animation::Dash:
		m_Animation->ChangeAnimation(m_vecSequenceKey[AnimDirectionIndex][3]);
		break;
	case EMonster_Animation::Land:
		m_Animation->ChangeAnimation(m_vecSequenceKey[AnimDirectionIndex][4]);
		break;
	}

	m_PrevMonsterAnim = m_MonsterAnim;
	
	m_PrevPos = m_Pos;
}

void CMonster::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);

	m_PrevMonsterAnim = m_MonsterAnim;

	if (m_Scene->FindObject("Player2D"))
	{
		if (m_EnableChase)
		{
			Vector3 MonsterPos = m_Body->GetWorldPos();

			Vector3 PlayerPos = m_Scene->FindObject("Player2D")->GetWorldPos();

			Vector3 Dir = PlayerPos - MonsterPos;

			Dir.y = 0.f;

			Dir.Normalize();

			m_Body->AddWorldPosition(Dir * m_MoveSpeed * g_DeltaTime);
		}
	}
}

float CMonster::InflictDamage(float Damage)
{
	Damage = CGameObject::InflictDamage(Damage);

	m_HP -= (int)Damage;

	if (m_HP <= 0)
	{
		Destroy();
	}

	return Damage;
}

void CMonster::AccessRangeCollisionBegin(const CollisionResult& result)
{
	if (result.Dest->GetCollisionProfile()->Name == "Player")
	{
		m_EnableChase = true;
	
		m_MonsterAnim = EMonster_Animation::Move;
	}
}

void CMonster::AccessRangeCollisionEnd(const CollisionResult& result)
{
	if (result.Dest->GetCollisionProfile()->Name == "Player")
	{
		m_EnableChase = false;
		m_MonsterAnim = EMonster_Animation::Move;
	}
}

void CMonster::DashRangeCollisionBegin(const CollisionResult& result)
{
	if (result.Dest->GetCollisionProfile()->Name == "Player")
	{
		m_EnableChase = true;
		m_MonsterAnim = EMonster_Animation::Dash;

		m_MoveSpeed = 125.f;
	}
}

void CMonster::DashRangeCollisionEnd(const CollisionResult& result)
{
	if (result.Dest->GetCollisionProfile()->Name == "Player")
	{
		m_EnableChase = true;
		m_MonsterAnim = EMonster_Animation::Move;

		m_MoveSpeed = 100.f;
	}
}

void CMonster::CollisionBegin(const CollisionResult& result)
{
	if(result.Dest->GetCollisionProfile()->Name == "PlayerAttack")
		InflictDamage(5);
}

void CMonster::CollisionEnd(const CollisionResult& result)
{
}

CMonster* CMonster::Clone() const
{
	return new CMonster(*this);
}
