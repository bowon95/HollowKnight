#include "Fade.h"
#include "UI/UIButton.h"
#include "UI/UIText.h"
#include "UI/UIProgressBar.h"
#include "UI/UINumber.h"
#include "UI/UIImage.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"
#include "../Scene/LoadingSceneInfo.h"
#include "Engine.h"

CFade::CFade() : 
	m_Opacity(1.0f), 
	m_State(EFade_State::Normal),
	m_NextScene(ENext_Scene::None)
{
	m_WindowTypeName = "Fade";
}

CFade::CFade(const CFade& Window) : CUIWindow(Window)
{
}

CFade::~CFade()
{
}

void CFade::Start()
{
	CUIWindow::Start();
}

bool CFade::Init()
{
	if (!CUIWindow::Init())
	{
		return false;
	}

	m_Fade = CreateWidget<CUIImage>("Fade");
	m_Fade->SetSize(1280.f, 1280.f);
	m_Fade->SetPos(0.f, 0.f);

	m_Fade->SetTexture("Fade", TEXT("FadeImage.png"));

	return true;
}

void CFade::Update(float DeltaTime)
{
	CUIWindow::Update(DeltaTime);
}

void CFade::PostUpdate(float DeltaTime)
{
	CUIWindow::PostUpdate(DeltaTime);

	if (m_State == EFade_State::FadeIn_Start)
	{
		m_Opacity -= DeltaTime / 0.5f;

		if (m_Opacity < 0.f)
		{
			m_Opacity = 0.f;
			SetEnable(false);
			SetState(EFade_State::Normal);
			//SetFade(false);
		}

		m_Fade->SetOpacity(m_Opacity);
	}

	if (m_State == EFade_State::FadeOut_Start)
	{
		if (!GetEnable())
		{
			SetEnable(true);
		}

		m_Opacity += DeltaTime / 0.5f;

		if (m_Opacity > 1.f)
		{
			m_Opacity = 1.f;
			SetState(EFade_State::FadeOut_End);

			// 로딩 Scene을 생성한다.
			switch (m_NextScene)
			{
			case ENext_Scene::TitleScene:
				CSceneManager::GetInst()->CreateNextScene(true);
				CSceneManager::GetInst()->CreateSceneInfo<CLoadingSceneInfo>(false, "EditorDefaultScene");
				break;

			case ENext_Scene::FirstScene:
				CSceneManager::GetInst()->CreateNextScene(true);
				CSceneManager::GetInst()->CreateSceneInfo<CLoadingSceneInfo>(false, "FirstScene");

				break;

			case ENext_Scene::SecondScene:
				CSceneManager::GetInst()->CreateNextScene(true);
				CSceneManager::GetInst()->CreateSceneInfo<CLoadingSceneInfo>(false, "SecondScene");

				break;

			case ENext_Scene::Dirtmouth:
				CSceneManager::GetInst()->CreateNextScene(true);
				CSceneManager::GetInst()->CreateSceneInfo<CLoadingSceneInfo>(false, "Dirtmouth");

				break;

			default:
				break;
			}
		}

		m_Fade->SetOpacity(m_Opacity);
	}
}

void CFade::Render()
{
	CUIWindow::Render();
}

CFade* CFade::Clone()
{
	return new CFade(*this);
}

void CFade::Save(FILE* File)
{
	CUIWindow::Save(File);
}

void CFade::Load(FILE* File)
{
	CUIWindow::Load(File);
}