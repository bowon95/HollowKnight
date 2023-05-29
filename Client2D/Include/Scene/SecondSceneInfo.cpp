#include "SecondSceneInfo.h"
#include "Scene/Scene.h"
#include "Component/SpriteComponent.h"
#include "Scene/SceneManager.h"
#include "Scene/SceneViewport.h"
#include "../UI/SecondSceneUI.h"
#include "../UI/StartSceneUI.h"
#include "../GameObject/Player2D.h"
#include "../GameObject/Monster.h"
#include "../GameObject/BackObj.h"
#include "../GameObject/WallObj.h"
#include "../GameObject/Effect.h"
#include "../GameObject/PortalObject.h"
#include "../GameObject/SecondPortal.h"


CSecondSceneInfo::CSecondSceneInfo()
{
	m_ClassTypeName = "SecondSceneInfo";
}

CSecondSceneInfo::~CSecondSceneInfo()
{
}

void CSecondSceneInfo::Start()
{
	m_Fade->SetState(EFade_State::FadeIn_Start);
}

bool CSecondSceneInfo::Init()
{
	CSceneInfo::Init();

	m_Owner->GetViewport()->CreateUIWindow<CSecondSceneUI>("SecondSceneUI");

	m_PlayerObject = m_Owner->CreateObject<CPlayer2D>("Player2D");

	SetPlayerObject(m_PlayerObject);

	//==================

	CSecondPortal* Portal = m_Owner->CreateObject<CSecondPortal>("SecondPortal");

	m_Fade = m_Owner->GetViewport()->CreateUIWindow<CFade>("Fade");
	m_Fade->SetState(EFade_State::FadeIn_Start);
	m_Fade->SetNextScene(ENext_Scene::SecondScene);



    return true;
}

void CSecondSceneInfo::Update(float DeltaTime)
{
	CSceneInfo::Update(DeltaTime);

}

void CSecondSceneInfo::SceneChangeComplete()
{
}
