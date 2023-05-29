#include "SecondSceneUI.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"

CSecondSceneUI::CSecondSceneUI()
{
    m_WindowTypeName = "SecondSceneUI";
}

CSecondSceneUI::CSecondSceneUI(const CSecondSceneUI& Window)
{
}

CSecondSceneUI::~CSecondSceneUI()
{
}

void CSecondSceneUI::Start()
{

    m_Scene->GetResource()->SoundPlay("CityOfTears");
}

bool CSecondSceneUI::Init()
{
    return false;
}

void CSecondSceneUI::Update(float DeltaTime)
{
}

void CSecondSceneUI::PostUpdate(float DeltaTime)
{
}

void CSecondSceneUI::Render()
{
}

CSecondSceneUI* CSecondSceneUI::Clone()
{
    return nullptr;
}

void CSecondSceneUI::Save(FILE* File)
{
}

void CSecondSceneUI::Load(FILE* File)
{
}

void CSecondSceneUI::StartButtonClick()
{
}
