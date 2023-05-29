//#include "GrimmRandom.h"
//#include "Grimm.h"
//#include "Scene/Scene.h"
//
//CGrimmRandom::CGrimmRandom()	:
//	m_RandomNum(0),
//	m_DelayTime(0.f),
//	m_GrimmBombOn(false),
//	m_GrimmSpikeOn(false),
//	m_GrimmToDiveOn(false),
//	m_GrimmCurtainOn(false)
//{
//}
//
//CGrimmRandom::~CGrimmRandom()
//{
//}
//
//bool CGrimmRandom::Run()
//{
//	if (m_Scene)
//	{
//		m_Grimm = (CGrimm*)m_Scene->FindObject("Grimm");
//	}
//	
//	if (m_Grimm && m_Grimm->GetDrawOn())
//	{
//		m_RandomNum = rand() % 4;
//
//		// Bomb, Spike, HitDown - Dash, Curtain
//		// 1 : Bomb
//		// 2 : Spike
//		// 3 : ToDive - Dive - Dash
//		// 4 : Curtain - SpawnBat
//
//		m_DelayTime += g_DeltaTime / g_DeltaTime;
//
//		if (m_DelayTime >= 3.0f)
//		{
//			if (m_RandomNum == 0)
//			{
//				m_GrimmBombOn = true;
//			}
//
//			else if (m_RandomNum == 1)
//			{
//				m_GrimmSpikeOn = true;
//			}
//
//			else if (m_RandomNum == 2)
//			{
//				m_GrimmToDiveOn = true;
//			}
//
//			else
//			{
//				m_GrimmCurtainOn = true;
//			}
//		}
//	}
//
//    return true;
//}
