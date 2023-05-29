#include "GrimmCurtain.h"
#include "Scene/Scene.h"
#include "Player2D.h"
#include "Grimm.h"
#include "GrimmRandom.h"
#include "Bat.h"

CGrimmCurtain::CGrimmCurtain()	: 
	m_DelayTime(0.f),
	m_CountBat(0.f),
	m_SpawnBatOn(false)
{
}

CGrimmCurtain::~CGrimmCurtain()
{
}

bool CGrimmCurtain::Run()
{
	if (!m_Random->GetGrimmCurtainOn())
		return false;

	m_Player = (CPlayer2D*)m_Scene->FindObject("Player2D");
	m_Grimm = (CGrimm*)m_Scene->FindObject("Grimm");

	m_Grimm->CurtainAnim();

	Vector3 GrimmPos = m_Grimm->GetWorldPos();
	Vector3 PlayerPos = m_Player->GetWorldPos();

	if (m_Player)
	{
		if (GrimmPos.x >= PlayerPos.x)
			m_Grimm->SetDir(-1);

		else
			m_Grimm->SetDir(1);
	}

	else
	{
		if (GrimmPos.x >= 645.f)
			m_Grimm->SetDir(-1);

		if (GrimmPos.x < 645.f)
			m_Grimm->SetDir(1);
	}

	//
	m_DelayTime += g_DeltaTime;														
																																				  //
	if (m_DelayTime >= 1.3f && m_CountBat < 1)												  
	{																				
		++m_CountBat;
																					
		SpawnBat();																	
																					
		m_DelayTime = 0.f;															
	}																				
																					
	if (m_DelayTime >= 1.4f && m_CountBat < 3)
	{																				
		++m_CountBat;
																					
		SpawnBat();																	
	}																				
																					
	if (m_CountBat > 2)
	{																				
		m_CountBat = 0;
		m_SpawnBatOn = false;
		m_Grimm->SetDrawOn(false);

	}																				


	return true;
}

void CGrimmCurtain::SpawnBat()
{
	m_Player = (CPlayer2D*)m_Scene->FindObject("Player2D");
	m_Grimm = (CGrimm*)m_Scene->FindObject("Grimm");

	m_SpawnBatOn = true;

	m_Bat = m_Scene->CreateObject<CBat>("Bat");


	if (m_Grimm->GetWorldPos().x >= 645.f)
	{
		if (m_CountBat == 0)
		{
			m_Bat->SetWorldPositionX(m_Grimm->GetWorldPos().x - 10.f);
			m_Bat->SetWorldPositionY(m_Grimm->GetWorldPos().y - 30.f);
		}

		else if (m_CountBat == 1)
		{
			m_Bat->SetWorldPositionX(m_Grimm->GetWorldPos().x - 10.f);
			m_Bat->SetWorldPositionY(m_Grimm->GetWorldPos().y - 130.f);
		}

		else
		{
			m_Bat->SetWorldPositionX(m_Grimm->GetWorldPos().x - 10.f);
			m_Bat->SetWorldPositionY(m_Grimm->GetWorldPos().y - 260.f);
		}
	}

	else
	{
		if (m_CountBat == 0)
		{
			m_Bat->SetWorldPositionX(m_Grimm->GetWorldPos().x + 10.f);
			m_Bat->SetWorldPositionY(m_Grimm->GetWorldPos().y - 30.f);
		}

		else if (m_CountBat == 1)
		{
			m_Bat->SetWorldPositionX(m_Grimm->GetWorldPos().x + 10.f);
			m_Bat->SetWorldPositionY(m_Grimm->GetWorldPos().y - 130.f);
		}

		else
		{
			m_Bat->SetWorldPositionX(m_Grimm->GetWorldPos().x + 10.f);
			m_Bat->SetWorldPositionY(m_Grimm->GetWorldPos().y - 260.f);
		}
	}
}
