#include "FirstSceneInfo.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"
#include "Scene/SceneViewport.h"
#include "../UI/FirstSceneUI.h"
#include "../UI/StartSceneUI.h"
#include "../GameObject/Player2D.h"
#include "../GameObject/Monster.h"
#include "../GameObject/BackObj.h"
#include "../GameObject/WallObj.h"
#include "../GameObject/Effect.h"
#include "../GameObject/Elderbug.h"
#include "../GameObject/PortalObject.h"
#include "../GameObject/GrimmLandPoint.h"
#include "../GameObject/GrimmChild.h"
#include "../GameObject/Grimm.h"
#include "Component/ColliderBox2D.h"
#include "../UI/Fade.h"

CFirstSceneInfo::CFirstSceneInfo()
{
	m_ClassTypeName = "FirstSceneInfo";
}

CFirstSceneInfo::~CFirstSceneInfo()
{
}

void CFirstSceneInfo::Start()
{
}

bool CFirstSceneInfo::Init()
{
	CSceneInfo::Init();

	m_Owner->GetViewport()->CreateUIWindow<CFirstSceneUI>("FirstSceneUI");

	m_PlayerObject = m_Owner->CreateObject<CPlayer2D>("Player2D");

	SetPlayerObject(m_PlayerObject);

	//==================

	CMonster* Monster = m_Owner->CreateObject<CMonster>("Monster");

	CPortalObject* Portal = m_Owner->CreateObject<CPortalObject>("PortalObject");


	//CElderbug* Elderbug = m_Owner->CreateObject<CElderbug>("Elderbug");

	m_Fade = m_Owner->GetViewport()->CreateUIWindow<CFade>("Fade"); 

	m_Fade->SetState(EFade_State::FadeIn_Start);

	return true;
}

void CFirstSceneInfo::Update(float DeltaTime)
{
	CSceneInfo::Update(DeltaTime);
}

void CFirstSceneInfo::SceneChangeComplete()
{
}
