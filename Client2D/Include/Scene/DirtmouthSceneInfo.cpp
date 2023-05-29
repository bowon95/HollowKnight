#include "DirtmouthSceneInfo.h"
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"
#include "Scene/SceneViewport.h"
#include "../UI/FirstSceneUI.h"
#include "../UI/StartSceneUI.h"
#include "../UI/DirtmouthUI.h"
#include "../GameObject/Player2D.h"
#include "../GameObject/GrimmChild.h"
#include "../GameObject/Effect.h"
#include "../GameObject/PortalObject.h"
#include "../GameObject/GrimmLandPoint.h"
#include "../GameObject/Grimm.h"
#include "../UI/Fade.h"

CDirtmouthSceneInfo::CDirtmouthSceneInfo()
{
	m_ClassTypeName = "DirtmouthSceneInfo";
}

CDirtmouthSceneInfo::~CDirtmouthSceneInfo()
{
}

void CDirtmouthSceneInfo::Start()
{
	m_Fade->SetState(EFade_State::FadeIn_Start);
}

bool CDirtmouthSceneInfo::Init()
{
	CSceneInfo::Init();

	m_Owner->GetViewport()->CreateUIWindow<CDirtmouthUI>("DirtmouthUI");

	m_Player = m_Owner->CreateObject<CPlayer2D>("Player");

	//m_Grimm = m_Owner->CreateObject<CGrimm>("Grimm");

	//m_GrimmChild = m_Owner->CreateObject<CGrimmChild>("GrimmChild");

	CGrimmLandPoint* GrimmLandPoint = m_Owner->CreateObject<CGrimmLandPoint>("GrimmLandPoint");

	m_Fade = m_Owner->GetViewport()->CreateUIWindow<CFade>("Fade");

	return true;
}

void CDirtmouthSceneInfo::Update(float DeltaTime)
{
	CSceneInfo::Update(DeltaTime);
}

void CDirtmouthSceneInfo::SceneChangeComplete()
{
}