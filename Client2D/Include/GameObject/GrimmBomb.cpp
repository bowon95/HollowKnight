//#include "GrimmBomb.h"
//#include "Scene/Scene.h"
//#include "Grimm.h"
//#include "GrimmRandom.h"
//#include "Bullet.h"
//
//CGrimmBomb::CGrimmBomb()	:
//	m_DelayTime(0.f),
//	m_CountBomb(0)
//{
//}
//
//CGrimmBomb::~CGrimmBomb()
//{
//}
//
//bool CGrimmBomb::Run()
//{
//	if (!m_Random->GetGrimmBombOn())
//		return false;
//
//	m_Grimm = (CGrimm*)m_Scene->FindObject("Grimm");
//
//	if (!m_Grimm || m_Grimm->GetGrimmBombOn() == false)
//		return false;
//
//	// Bomb 애니메이션으로 바꿔준다.
//	m_Grimm->SetGrimmAnimation(EGrimm_Animation::GrimmBomb);
//
//	m_DelayTime += g_DeltaTime / g_DeltaTime;
//
//	if (m_DelayTime >= 1.f && m_CountBomb == 0)
//	{
//		FireBalls();
//
//		++m_CountBomb;
//	}
//
//	else if (m_DelayTime >= 3.f && m_CountBomb == 1)
//	{
//		FireBalls();
//
//		++m_CountBomb;
//
//	}
//
//	else if (m_DelayTime >= 5.f && m_CountBomb == 2)
//	{
//		FireBalls();
//
//		++m_CountBomb;
//	}
//
//	else if (m_CountBomb == 3)
//	{
//		m_DelayTime = 0.f;
//
//		//m_Grimm->SetDrawOn(false);
//		//m_Grimm->SetGrimmBombOn(false);
//
//		return false; // 이러면 아예 나가지 않을까.
//	}
//
//	return true;
//}
//
//void CGrimmBomb::FireBalls()
//{
//	Vector3 GrimmPos = m_Grimm->GetWorldPos();
//
//	for (int i = 1; i < 15; ++i) 
//	{
//		m_FireBalls[i] = m_Scene->CreateObject<CBullet>("Bullet");
//		m_FireBalls[i]->SetWorldRotation(m_Grimm->GetWorldRot() + Vector3(0.f, 0.f, i * 30.f));
//		m_FireBalls[i]->SetWorldPosition(GrimmPos);
//		m_FireBalls[i]->SetCollisionProfileName("Monster");
//	}
//}
