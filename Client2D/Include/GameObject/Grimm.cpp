#include "Grimm.h"
#include "Player2D.h"
#include "Input.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Component/ColliderSphere2D.h"
#include "Component/ColliderOBB2D.h"
#include "Component/WallComponent.h"
#include "GrimmChild.h"
#include "Bullet.h"
#include "Scene/Scene.h"
#include "Bat.h"
#include "Spike.h"

CGrimm::CGrimm() :
	m_LoadingTime(0.f),
	m_RoarOn(false),
	m_FightOn(false),
	m_DrawOn(false),
	m_RandomNum(0),
	m_GrimmBombOn(false),
	m_GrimmSpikeOn(false),
	m_GrimmToDiveOn(false),
	m_GrimmCurtainOn(false),
	m_CountBomb(0),
	m_CountSpawnBat(0),
	m_CountSpike(0),
	m_SpikeTime(0.f),
	m_DiveTime(0.f),
	m_GrimmDiveStartOn(false),
	m_DashCollisionOn(false),
	m_DashOn(false)
{
	SetTypeID<CGrimm>();

	m_ObjectTypeName = "Grimm";

	m_GrimmAnim = EGrimm_Animation::First_GrimmAppear;

}

CGrimm::CGrimm(const CGrimm& Obj)
{
	m_Body = (CColliderOBB2D*)FindComponent("Body");
	m_Sprite = (CSpriteComponent*)FindComponent("Sprite");
	m_Wall = (CWallComponent*)FindComponent("Wall");
}

CGrimm::~CGrimm()
{
}

void CGrimm::Start()
{
	CGameObject::Start();

	// 테스트용.
	// CInput::GetInst()->AddBindFunction<CGrimm>("Test", Input_Type::Down, this, &CGrimm::Roar, m_Scene);
	// CInput::GetInst()->AddBindFunction<CGrimm>("EndGame", Input_Type::Down, this, &CGrimm::EndGame, m_Scene);

	m_Body = CreateComponent<CColliderOBB2D>("Body");
	m_Sprite = CreateComponent<CSpriteComponent>("sprite");
	m_Wall = CreateComponent<CWallComponent>("Wall");

	SetRootComponent(m_Body);

	m_Body->SetCollisionProfile("Monster");
	m_Body->AddChild(m_Sprite);

	m_Body->SetBoxHalfSize(99.f, 203.f);
	m_Body->SetPivot(0.5f, 0.5f);
	m_Body->SetWorldPosition(500.f, 500.f);

	m_Wall->SetFallStartY(GetWorldPos().y);
	m_Wall->SetGravityAccel(25.f);

	m_Sprite->SetPivot(0.5f, 0.5f);
	m_Sprite->SetRelativeScale(198.f, 406.f);

	if (m_Scene)
		m_Player = (CPlayer2D*)m_Scene->FindObject("Player2D");

	m_Animation = m_Sprite->SetAnimation<CAnimation2D>("Grimm");

	// BeforeFight
	m_Animation->AddAnimation("First_GrimmAppear", "First_GrimmAppear", 1.f, 0.5f, false); 
	m_Animation->AddAnimation("GrimmStretch", "GrimmStretch", 1.f, 1.f, false);
	m_Animation->AddAnimation("GrimmAbsorb1", "GrimmAbsorb1", 1.f, 2.f, false);	
	m_Animation->AddAnimation("GrimmAbsorb2", "GrimmAbsorb2", 1.f, 1.f, false); 
	m_Animation->AddAnimation("GrimmRoar", "GrimmRoar", 1.f, 1.5f, true); 

	// Fight Pattern
	m_Animation->AddAnimation("GrimmBomb", "GrimmBomb", 1.f, 2.f, true);

	m_Animation->AddAnimation("CurtainLeft", "CurtainLeft", 1.f, 1.f, true);
	m_Animation->AddAnimation("CurtainRight", "CurtainRight", 1.f, 1.f, true);

	m_Animation->AddAnimation("GrimmDashLeft", "GrimmDashLeft", 1.f, 1.f, false);
	m_Animation->AddAnimation("GrimmDashRight", "GrimmDashRight", 1.f, 1.f, false);

	m_Animation->AddAnimation("GrimmToSpike", "GrimmToSpike", 1.f, 1.f, false);
	m_Animation->AddAnimation("GrimmSpike", "GrimmSpike", 1.f, 2.f, true);

	m_Animation->AddAnimation("DiveLeft", "DiveLeft", 1.f, 3.f, true);
	m_Animation->AddAnimation("DiveRight", "DiveRight", 1.f, 3.f, true);
	m_Animation->AddAnimation("ToDiveLeft", "ToDiveLeft", 1.f, 1.2f, true);
	m_Animation->AddAnimation("ToDiveRight", "ToDiveRight", 1.f, 1.2f, true, false);
	m_Animation->AddAnimation("Disappear", "Disappear", 1.f, 1.f, false);

	// Left
	m_vecSequenceKey[0].push_back("ToDiveLeft");
	m_vecSequenceKey[0].push_back("DiveLeft");
	m_vecSequenceKey[0].push_back("GrimmDashLeft");
	m_vecSequenceKey[0].push_back("CurtainLeft");

	// Right
	m_vecSequenceKey[1].push_back("ToDiveRight");
	m_vecSequenceKey[1].push_back("DiveRight");
	m_vecSequenceKey[1].push_back("GrimmDashRight");
	m_vecSequenceKey[1].push_back("CurtainRight");

	// BeforeFight 용 세팅.
	m_Animation->SetCurrentEndFunction("First_GrimmAppear", this, &CGrimm::BeforeAttack);
	m_Animation->SetCurrentEndFunction("GrimmAbsorb1", this, &CGrimm::BeforeAttack);
	m_Animation->SetCurrentEndFunction("GrimmAbsorb2", this, &CGrimm::BeforeAttack);

	m_Animation->SetCurrentEndFunction("Disappear", this, &CGrimm::DrawRandomOn);
	m_Animation->AddCurrentNotify<CGrimm>("CurtainLeft", "CurtainLeft", 6, this, &CGrimm::SpawnBat);
	m_Animation->AddCurrentNotify<CGrimm>("CurtainRight", "CurtainRight", 6, this, &CGrimm::SpawnBat);
	m_Animation->SetCurrentEndFunction("GrimmToSpike", this, &CGrimm::Spike);
	m_Animation->SetCurrentEndFunction("GrimmDashRight", this, &CGrimm::Disappear);
	m_Animation->SetCurrentEndFunction("GrimmDashLeft", this, &CGrimm::Disappear);


	m_Body->SetCollisionCallback<CGrimm>(ECollision_Result::Collision, this, &CGrimm::CollisionBegin); 
	m_Body->SetCollisionCallback<CGrimm>(ECollision_Result::Release, this, &CGrimm::CollisionEnd);


}

bool CGrimm::Init()
{
	CGameObject::Init();

	m_GrimmAnim = EGrimm_Animation::First_GrimmAppear;

	m_Dir = -1;

	return true;
}

void CGrimm::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);

	// 3초간 Roar 후 Fight 패턴.
	if (m_RoarOn && !m_FightOn)
	{
		m_LoadingTime += DeltaTime;

		if (m_LoadingTime >= 3.f)
		{
			m_RoarOn = false;
			m_FightOn = true;
			m_LoadingTime = 0.f;
		}
	}

	// (하나의 공격 패턴이 끝나고) 뽑기가 끝났을 때 4초 후 다시 뽑기 On.
	if (m_FightOn && !m_DrawOn)
	{
		m_LoadingTime += DeltaTime / DeltaTime;

		if (m_LoadingTime >= 4.f)
		{
			m_DrawOn = true;
			DrawRandom(); // 뽑기 함수 호출.
		}
	}

	// 실시간으로 위치 값을 받아줘야하기 때문에 Update에서 실행.
	if (m_Scene)
		m_Player = (CPlayer2D*)m_Scene->FindObject("Player2D");
}

void CGrimm::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
	
	int	AnimDirectionIndex = 0;

	if (m_Dir == -1)
		AnimDirectionIndex = 0;

	else
		AnimDirectionIndex = 1;

	switch (m_GrimmAnim)
	{
	case EGrimm_Animation::First_GrimmAppear:
		m_Animation->ChangeAnimation("First_GrimmAppear");
		m_Sprite->SetRelativeScale(264.f, 441.f);
		break;
	case EGrimm_Animation::GrimmStretch:
		m_Animation->ChangeAnimation("GrimmStretch");
		m_Sprite->SetRelativeScale(546.f, 816.f);
		break;
	case EGrimm_Animation::GrimmAbsorb1:
		m_Animation->ChangeAnimation("GrimmAbsorb1");
		m_Sprite->SetRelativeScale(546.f, 816.f);
		break;
	case EGrimm_Animation::GrimmAbsorb2:
		m_Animation->ChangeAnimation("GrimmAbsorb2");
		m_Sprite->SetRelativeScale(390.f, 508.f);
		break;
	case EGrimm_Animation::GrimmRoar:
		m_Animation->ChangeAnimation("GrimmRoar");
		m_Sprite->SetRelativeScale(514.f, 438.f);
		break;
	// 아래는 Fight Pattern.
	case EGrimm_Animation::GrimmBomb:
		m_Animation->ChangeAnimation("GrimmBomb");
		m_Sprite->SetRelativeScale(395.f, 392.f);
		m_Body->SetWorldPosition(744.f, 800.f, 0.f);
		break;
	case EGrimm_Animation::GrimmToSpike:
		m_Animation->ChangeAnimation("GrimmToSpike"); 
		m_Sprite->SetRelativeScale(400.16f, 414.f);
		m_Body->SetWorldPosition(640.f, 300.f);
		break;
	case EGrimm_Animation::GrimmSpike:
		m_Animation->ChangeAnimation("GrimmSpike");
		m_Sprite->SetRelativeScale(394.f, 445.f);
		m_Body->SetWorldPosition(640.f, 300.f);
		break;
	case EGrimm_Animation::GrimmToDive:
		m_Animation->ChangeAnimation(m_vecSequenceKey[AnimDirectionIndex][0]);
		m_Sprite->SetRelativeScale(900.f, 525.f);
		break;
	case EGrimm_Animation::GrimmDive:
		m_Animation->ChangeAnimation(m_vecSequenceKey[AnimDirectionIndex][1]);
		m_Sprite->SetRelativeScale(900.f, 525.f);
		break;
	case EGrimm_Animation::GrimmDash:
		m_Animation->ChangeAnimation(m_vecSequenceKey[AnimDirectionIndex][2]);
		m_Sprite->SetRelativeScale(688.f, 601.f);
		break;
	case EGrimm_Animation::GrimmCurtain:
		m_Animation->ChangeAnimation(m_vecSequenceKey[AnimDirectionIndex][3]);
		m_Sprite->SetRelativeScale(546.f, 444.f);
		if(m_Dir = -1)
			m_Body->SetWorldPosition(900.f, 300.f);
		else
			m_Body->SetWorldPosition(380, 300.f);
		break;
	case EGrimm_Animation::Disappear:
		m_Animation->ChangeAnimation("Disappear");
		m_Sprite->SetRelativeScale(283.f, 899.f);
		break;
	}

	CheckAttack();

	Vector3 GrimmPos = GetWorldPos();
}

float CGrimm::InflictDamage(float Damage)
{
	return 0.0f;
}

void CGrimm::CollisionBegin(const CollisionResult& result)
{
	if (result.Dest->GetCollisionProfile()->Name == "GrimmChild")
	{
		m_GrimmAnim = EGrimm_Animation::GrimmAbsorb1;
	}

	if (result.Dest->GetCollisionProfile()->Name == "Player")
	{
		Disappear();
	}
}

void CGrimm::CollisionEnd(const CollisionResult& result)
{
	if (result.Dest->GetCollisionProfile()->Name == "Player2D")
	{
		if (m_GrimmAnim == EGrimm_Animation::GrimmDash)
			m_DashCollisionOn = false;
	}
}

void CGrimm::CheckAttack()
{
	if (m_GrimmBombOn)
	{
		GrimmBomb();
	}

	if (m_GrimmCurtainOn)
	{
		GrimmCurtain();
	}

	if (m_GrimmSpikeOn && m_CountSpike == 0)
	{
		Spike();
	}

	if (m_GrimmSpikeOn && m_CountSpike == 1)
	{
		m_SpikeTime += g_DeltaTime;

		if (m_SpikeTime >= 4.f)
			m_GrimmAnim = EGrimm_Animation::Disappear;
	}

	if (m_GrimmToDiveOn)
	{
		//m_LoadingTime += g_DeltaTime;

		Dive();

	}

	if (m_GrimmDiveStartOn)
	{
		if (m_Dir = -1)
		{
			m_Body->AddWorldPositionX(-100.f * g_DeltaTime);
			m_Body->AddWorldPositionY(-100.f * g_DeltaTime);
		}
		
		else
		{
			m_Body->AddWorldPositionX(100.f * g_DeltaTime);
			m_Body->AddWorldPositionY(-100.f * g_DeltaTime);
		}


		if (GetWorldPos().y <= 365.f)
			Dash();
	}
}

void CGrimm::BeforeAttack()
{
	if(m_Animation->GetCurrentAnimationName() == "First_GrimmAppear")
		m_GrimmAnim = EGrimm_Animation::GrimmStretch;

	else if(m_Animation->GetCurrentAnimationName() == "GrimmAbsorb1")
		m_GrimmAnim = EGrimm_Animation::GrimmAbsorb2;

	else if (m_Animation->GetCurrentAnimationName() == "GrimmAbsorb2")
	{
		m_RoarOn = true;
		//m_DrawOn = true;

		m_GrimmAnim = EGrimm_Animation::GrimmRoar;
	}
}

void CGrimm::DrawRandom()
{
	m_RandomNum = rand() % 4;

	// Bomb, Spike, HitDown - Dash, Curtain
	// 1 : Spike
	// 2 : Bomb
	// 3 : ToDive - Dive - Dash
	// 4 : Curtain - SpawnBat

	if (m_RandomNum == 0)
	{
		//m_LoadingTime >= 0.f;
		//m_GrimmSpikeOn = true;
		m_GrimmToDiveOn = true;
		//m_GrimmBombOn = true;
		//m_GrimmCurtainOn = true;



	}

	else if (m_RandomNum == 1)
	{
		//m_LoadingTime >= 0.f;
		//m_GrimmBombOn = true;
		m_GrimmToDiveOn = true;
		//m_GrimmSpikeOn = true;



	}

	else if (m_RandomNum == 2)
	{
		//m_LoadingTime >= 0.f;
		//m_GrimmCurtainOn = true;
		m_GrimmToDiveOn = true;
		//m_GrimmBombOn = true;
		//m_GrimmSpikeOn = true;


	}

	else
	{
		//m_GrimmBombOn = true;
		m_GrimmToDiveOn = true;
		//m_GrimmBombOn = true;
		//m_GrimmCurtainOn = true;


	}
	
}

void CGrimm::GrimmBomb()
{
	// Bomb 애니메이션으로 바꿔준다.
	m_GrimmAnim = EGrimm_Animation::GrimmBomb;

	m_Wall->SetPhysicsSimulate(false);
	m_Wall->SetGravityAccel(0.f);

	m_LoadingTime += g_DeltaTime;

	if (m_LoadingTime >= 2.f && m_CountBomb == 0)
	{
		++m_CountBomb;
	}

	else if (m_LoadingTime >= 3.f && m_CountBomb == 1)
	{
		++m_CountBomb;

		FireBalls();
	}

	else if (m_LoadingTime >= 5.f && m_CountBomb == 2)
	{
		++m_CountBomb;

		FireBalls();

	}

	else if (m_LoadingTime >= 7.f && (m_CountBomb == 3))
	{
		++m_CountBomb;

		FireBalls();

		m_GrimmAnim = EGrimm_Animation::Disappear;

		m_LoadingTime = 0.f;
		m_GrimmBombOn = false;
		m_CountBomb = 0;
	}
}

void CGrimm::GrimmCurtain()
{
	m_GrimmAnim = EGrimm_Animation::GrimmCurtain;

	if (m_Player)
	{
		Vector3 GrimmPos = m_Body->GetWorldPos();
		Vector3 PlayerPos = m_Player->GetWorldPos();

		if (GrimmPos.x >= PlayerPos.x)
			m_Dir = -1;

		else
			m_Dir = 1;
	}
}

void CGrimm::SpawnBat()
{
	m_Bat = m_Scene->CreateObject<CBat>("Bat");

	
	if (m_Dir == -1)
	{
		if (m_CountSpawnBat == 0)
		{
			m_Bat->SetWorldPositionX(m_Body->GetWorldPos().x - 10.f);
			m_Bat->SetWorldPositionY(m_Body->GetWorldPos().y - 20.f);

			++m_CountSpawnBat;
		}

		else if (m_CountSpawnBat == 1)
		{
			m_Bat->SetWorldPositionX(m_Body->GetWorldPos().x - 10.f);
			m_Bat->SetWorldPositionY(m_Body->GetWorldPos().y - 100.f);

			++m_CountSpawnBat;

		}

		else
		{
			m_Bat->SetWorldPositionX(m_Body->GetWorldPos().x - 10.f);
			m_Bat->SetWorldPositionY(m_Body->GetWorldPos().y - 230.f);

			m_GrimmCurtainOn = false;

			m_GrimmAnim = EGrimm_Animation::Disappear;

			m_CountSpawnBat = 0;
		}
	}

	else
	{
		if (m_CountSpawnBat == 0)
		{
			m_Bat->SetWorldPositionX(m_Body->GetWorldPos().x + 10.f);
			m_Bat->SetWorldPositionY(m_Body->GetWorldPos().y - 20.f);

			++m_CountSpawnBat;

		}

		else if (m_CountSpawnBat == 1)
		{
			m_Bat->SetWorldPositionX(m_Body->GetWorldPos().x + 10.f);
			m_Bat->SetWorldPositionY(m_Body->GetWorldPos().y - 100.f);

			++m_CountSpawnBat;

		}

		else
		{
			m_Bat->SetWorldPositionX(m_Body->GetWorldPos().x + 10.f);
			m_Bat->SetWorldPositionY(m_Body->GetWorldPos().y - 230.f);

			m_GrimmCurtainOn = false;

			m_GrimmAnim = EGrimm_Animation::Disappear;

			m_CountSpawnBat = 0;
		}
	}
}

void CGrimm::FireBalls()
{
	Vector3 GrimmPos = GetWorldPos();

	for (int i = 1; i < 15; ++i)
	{
		m_FireBalls[i] = m_Scene->CreateObject<CBullet>("Bullet");
		m_FireBalls[i]->SetWorldRotation(GetWorldRot() + Vector3(0.f, 0.f, i * 30.f));
		m_FireBalls[i]->SetWorldPosition(GrimmPos);


		m_FireBalls[i]->SetCollisionProfileName("Monster");
	}
}

void CGrimm::DrawRandomOn()
{
	m_DrawOn = false;
	m_GrimmSpikeOn = false;
}

void CGrimm::Spike()
{
	++m_CountSpike;

	m_GrimmAnim = EGrimm_Animation::GrimmSpike;

	// 가시생성
	for (int i = 0; i < 8; ++i)
	{
		m_Spike[i] = m_Scene->CreateObject<CSpike>("Spike");

		m_Spike[i]->SetWorldPositionX(94.6f + i * 250.f);
		m_Spike[i]->SetWorldPositionY(200.f);
		m_Spike[i]->SetCollisionProfileName("Monster");
	}
}

void CGrimm::Dive()
{// Player의 방향을 구하고 그 방향으로 땅에 닿을 때까지 돌진
	if (m_Player)
	{
		m_DiveTime += g_DeltaTime;

		Vector3 GrimmPos = m_Body->GetWorldPos();


		if (GrimmPos.x > m_Player->GetWorldPos().x)
		{
			m_Dir = -1;
			m_GrimmAnim = EGrimm_Animation::GrimmToDive;
			m_Body->SetWorldPosition(900.f, 800.f);

		}

		else
		{
			m_Dir = 1;
			m_GrimmAnim = EGrimm_Animation::GrimmToDive;
			m_Body->SetWorldPosition(300.f, 800.f);

		}

		m_Wall->SetPhysicsSimulate(false);
		m_Wall->SetGravityAccel(0.f);

		bool Check = false;

		if (m_DiveTime >= 3.f && Check == false && m_GrimmToDiveOn)
		{
			m_DiveTime = 0.f;

			m_GrimmToDiveOn = false;

			DiveStart();

			/*m_EnableDraw = false;*/
			Check = true;
		}
	}

	else
		return;
}

void CGrimm::DiveStart()
{
	m_GrimmDiveStartOn = true;

	m_DiveTime += g_DeltaTime;

	m_GrimmAnim = EGrimm_Animation::GrimmDive;

	Vector3 GrimmPos = m_Body->GetWorldPos();
	Vector3 PlayerPos = m_Player->GetWorldPos();

	//if (GrimmPos.x > PlayerPos.x)
	//{
	//	Vector3 Dir = (PlayerPos /*+ Vector3(10.f, 0.f, 0.f)*/ - GrimmPos);

	//	Dir.Normalize();

	//	m_Wall->SetPhysicsSimulate(true);
	//	m_Wall->SetGravityAccel(3.f);
	//	m_Wall->SetFallStartY(GrimmPos.y);

	//	// 하강하는 속도를 같게 해주기 위해. sqrt 함수는 루트. 9는 Velocity값.
	//	float DeltaX = 3.f / sqrt(2);
	//	float DeltaY = DeltaX;
	//	//

	//	m_Body->AddWorldPosition(Dir * 170.f * g_DeltaTime);
	//	m_Body->AddWorldPosition(-DeltaX, -DeltaY, 0);
	//}
	if (GrimmPos.x > PlayerPos.x)
	{
		//Vector3 Dir = (PlayerPos /*+ Vector3(10.f, 0.f, 0.f)*/ - GrimmPos);

		//Dir.Normalize();

		//m_Wall->SetPhysicsSimulate(true);
		//m_Wall->SetGravityAccel(3.f);
		//m_Wall->SetFallStartY(GrimmPos.y);

		//m_Body->AddWorldPositionX(Dir.x * -170.f * g_DeltaTime);
		//m_Body->AddWorldPositionY(Dir.y * -170.f * g_DeltaTime);
		//==
		//Vector3 Dir = (PlayerPos /*+ Vector3(10.f, 0.f, 0.f)*/ - GrimmPos);

		//Dir.Normalize();

		m_Wall->SetPhysicsSimulate(true);
		m_Wall->SetGravityAccel(3.f);
		m_Wall->SetFallStartY(GrimmPos.y);

	
	}

	else
	{
	//	m_Wall->SetPhysicsSimulate(true);
	//	m_Wall->SetGravityAccel(3.f);

	//	Vector3 Dir = (PlayerPos /*+ Vector3(-10.f, 0.f, 0.f)*/ - GetWorldPos().x);

	//	Dir.Normalize();

	//	m_Body->AddWorldPositionX(Dir.x * 170.f * g_DeltaTime);
	//	m_Body->AddWorldPositionY(Dir.y * -170.f * g_DeltaTime);
		//==
		m_Wall->SetPhysicsSimulate(true);
		m_Wall->SetGravityAccel(3.f);
		m_Wall->SetFallStartY(GrimmPos.y);

		m_Body->AddWorldPositionX(-170.f * g_DeltaTime);
		m_Body->AddWorldPositionY(-170.f * g_DeltaTime);
	}
	//else
	//{
	//	m_Wall->SetPhysicsSimulate(true);
	//	m_Wall->SetGravityAccel(3.f);

	//	Vector3 Dir = (PlayerPos /*+ Vector3(-10.f, 0.f, 0.f)*/ - GetWorldPos().x);

	//	Dir.Normalize();

	//	float DeltaX = -3.f / sqrt(2);
	//	float DeltaY = DeltaX;

	//	m_Body->AddWorldPosition(Dir * 170.f * g_DeltaTime);
	//	m_Body->AddWorldPosition(-DeltaX, DeltaY, 0);
	//}
}

void CGrimm::Dash()
{
	m_LoadingTime += g_DeltaTime;

	m_GrimmAnim = EGrimm_Animation::GrimmDash;

	if (m_Scene->FindObject("Player2D"))
	{
		Vector3 GrimmPos = m_Body->GetWorldPos();
		Vector3 PlayerPos = m_Player->GetWorldPos();

		// 왼쪽 방향으로 Dash.
		if (GrimmPos.x >= PlayerPos.x)
		{
			m_Dir = -1;

			m_Animation->ChangeAnimation("GrimmDashLeft");

			//Vector3 Dir = (m_PlayerPos - GrimmPos);

			//Dir.y = 0.f;

			//Dir.Normalize();

			// 150.f : m_MoveSpeed
			m_Body->AddWorldPositionX(/*Dir * */350.f * -1.5f * g_DeltaTime);

			if (GrimmPos.x <= 10.f)
				m_Dir = 1;
		}

		// 오른쪽 방향으로 Dash.
		else
		{
			m_Dir = 1;

			m_Animation->ChangeAnimation("GrimmDashRight");

			// 150.f : m_MoveSpeed
			m_Body->AddWorldPositionX(350.f * 1.5f * g_DeltaTime);
		}

		// 맵 가로 크기 : 1920
		if (GrimmPos.x <= 120.f || GrimmPos.x >= 1800.f || m_DashCollisionOn)
		{
			m_DashOn = false;
			m_DashCollisionOn = false;
			m_LoadingTime = 0.f;

			m_GrimmDiveStartOn = false;

		}
	}
}

void CGrimm::Disappear()
{
	m_GrimmAnim = EGrimm_Animation::Disappear;
	m_GrimmDiveStartOn = false;
}
