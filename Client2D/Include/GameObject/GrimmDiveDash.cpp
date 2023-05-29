#include "GrimmDiveDash.h"
#include "Scene/Scene.h"
#include "Player2D.h"
#include "Grimm.h"
#include "GrimmRandom.h"

CGrimmDiveDash::CGrimmDiveDash()	:
	m_DiveTime(0.f),
	m_ToDiveOn(false),
	m_DiveOn(false)
{
}

CGrimmDiveDash::~CGrimmDiveDash()
{
}

bool CGrimmDiveDash::Run()
{
	if (!m_Random->GetGrimmToDiveOn())
		return false;

	m_Player = (CPlayer2D*)m_Scene->FindObject("Player2D");
	m_Grimm = (CGrimm*)m_Scene->FindObject("Grimm");

	// Player의 방향을 구하고 그 방향으로 땅에 닿을 때까지 돌진
	if (m_Player)
	{
		m_DiveTime += g_DeltaTime;

		Vector3 GrimmPos = m_Grimm->GetWorldPos();
		Vector3 PlayerPos = m_Player->GetWorldPos();

		if (GrimmPos.x > PlayerPos.x)
		{
			m_Grimm->SetDir(-1);
			m_Grimm->ToDiveAnim();
			m_Grimm->SetWorldPosition(900.f, 800.f);
		}

		else
		{
			m_Grimm->SetDir(1);
			m_Grimm->ToDiveAnim();
			m_Grimm->SetWorldPosition(300.f, 800.f);
		}


		bool Check = false;

		if (m_DiveTime >= 3.f && Check == false && m_ToDiveOn/*&& m_EnableDraw*/)
		{
			m_DiveTime = 0.f;

			m_ToDiveOn = false;

			Dive();

			/*m_EnableDraw = false;*/
			Check = true;
		}
	}

	else
		return false;

    return true;
}

void CGrimmDiveDash::Dive()
{
	m_DiveOn = true;

	m_DiveTime += g_DeltaTime;

	m_Grimm->DiveAnim();

	Vector3 GrimmPos = m_Grimm->GetWorldPos();
	Vector3 PlayerPos = m_Player->GetWorldPos();

	if (GrimmPos.x > PlayerPos.x)
	{
		Vector3 Dir = (PlayerPos /*+ Vector3(10.f, 0.f, 0.f)*/ - GrimmPos);

		Dir.Normalize();

		// 하강하는 속도를 같게 해주기 위해. sqrt 함수는 루트. 9는 Velocity값.
		float DeltaX = 3.f / sqrt(2);
		float DeltaY = DeltaX;
		//

		m_Grimm->AddWorldPosition(Dir * 300.f * g_DeltaTime); // 300.f 는 m_MoveSpeed. 
		m_Grimm->AddWorldPosition(-DeltaX, -DeltaY, 0);

		m_Grimm->SetDrawOn(false);

	}

	else
	{
		Vector3 Dir = (PlayerPos /*+ Vector3(-10.f, 0.f, 0.f)*/ - GrimmPos.x);

		Dir.Normalize();

		float DeltaX = -3.f / sqrt(2);
		float DeltaY = DeltaX;

		m_Grimm->AddWorldPosition(Dir * 300.f * g_DeltaTime);
		m_Grimm->AddWorldPosition(-DeltaX, DeltaY, 0);

		m_Grimm->SetDrawOn(false);

	}
}
