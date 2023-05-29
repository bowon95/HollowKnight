#include "DirtmouthUI.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"

CDirtmouthUI::CDirtmouthUI()
{
}

CDirtmouthUI::CDirtmouthUI(const CDirtmouthUI& Window)
{
}

CDirtmouthUI::~CDirtmouthUI()
{
}

void CDirtmouthUI::Start()
{
	m_Scene->GetResource()->SoundPlay("Grimm");
}

bool CDirtmouthUI::Init()
{
	return true;
}

void CDirtmouthUI::Update(float DeltaTime)
{
}

void CDirtmouthUI::PostUpdate(float DeltaTime)
{
}

void CDirtmouthUI::Render()
{
}

CDirtmouthUI* CDirtmouthUI::Clone()
{
	return nullptr;
}

void CDirtmouthUI::Save(FILE* File)
{
}

void CDirtmouthUI::Load(FILE* File)
{
}

void CDirtmouthUI::StartButtonClick()
{
}
