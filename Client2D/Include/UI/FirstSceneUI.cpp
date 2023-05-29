#include "FirstSceneUI.h"
#include "UI/UIButton.h"
#include "UI/UIText.h"
#include "UI/UIImage.h"
#include "UI/UIProgressBar.h"
#include "UI/UINumber.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"
#include "../Scene/LoadingSceneInfo.h"
#include "../Scene/FirstSceneInfo.h"
#include "Engine.h"
#include "../GameObject/BackObj.h"
#include "../GameObject/Player2D.h"
#include "Animation/Animation2D.h"
#include "Component/ColliderBox2D.h"
#include "GameObject/GameObject.h"

CFirstSceneUI::CFirstSceneUI()
{
    m_WindowTypeName = "FirstSceneUI";

}

CFirstSceneUI::CFirstSceneUI(const CFirstSceneUI& Window) :
    CUIWindow(Window)
{
    m_Button = FindWidget<CUIButton>("Button");
    m_Title = FindWidget<CUIText>("Title");
    m_Number = FindWidget<CUINumber>("Number");
    m_Back = FindWidget<CUIImage>("Back");
}

CFirstSceneUI::~CFirstSceneUI()
{
}

void CFirstSceneUI::Start()
{
    CUIWindow::Start();

    m_Scene->GetResource()->SoundPlay("CrossRoads");
}

bool CFirstSceneUI::Init()
{
    CUIWindow::Init();

    //== HP
    m_HP = CreateWidget<CUIImage>("HP");
    m_HP->SetPos(50.f, 600.f);
    m_HP->SetSize(57.f, 70.f);
    m_HP->SetTexture("HP", TEXT("HP1.png"));


    //    TEXT("HPFull.png"));
    //m_ProgressBar = CreateWidget<CUIProgressBar>("ProgressBar");

    //m_ProgressBar->SetPos(50.f, 600.f);
    //m_ProgressBar->SetSize(630.f, 70.f);

    ////m_ProgressBar->SetImageTint(EProgressBarTextureType::Back, 100, 100, 100, 255);
    ////m_ProgressBar->SetImageTint(EProgressBarTextureType::Bar, 255, 255, 255, 255);

    //m_ProgressBar->SetTexture(EProgressBarTextureType::Bar, "HPBar",
    //    TEXT("HPFull.png"));
    //m_ProgressBar->SetTexture(EProgressBarTextureType::Back, "HPBarBack",
    //    TEXT("HPEmpty.png"));

    //m_ProgressBar->SetProgressBarMin(0.f);
    //m_ProgressBar->SetProgressBarMax(100.f);
    //m_ProgressBar->SetValue(50.f);
    //m_ProgressBar->SetBarDir(EProgressBarDir::LeftToRight);


    m_Number = CreateWidget<CUINumber>("Number");

    m_Number->SetPos(1000.f, 700.f);
    m_Number->SetSize(20.f, 30.f);

    m_Number->SetNumber(2392);

    m_Number->SetTexture("Number", TEXT("Number.png"));

    for (int i = 0; i < 10; ++i)
    {
        m_Number->AddFrameData(Vector2(i * 46.4f, 0.f), Vector2((i + 1) * 46.4f, 68.5f));
    }

    return true;
}

void CFirstSceneUI::Update(float DeltaTime)
{
    CUIWindow::Update(DeltaTime);

    float FPS = CEngine::GetInst()->GetFPS();

    m_Number->SetNumber((unsigned int)FPS);
}

void CFirstSceneUI::PostUpdate(float DeltaTime)
{
    CUIWindow::PostUpdate(DeltaTime);

    /*if (m_Player)
    {
        m_Player = (CPlayer2D*)m_Scene->FindObject("Player2D");
        int PlayerHP = m_Scene->GetPlayer()->GetHP();

        if (PlayerHP <= 0)
        {
           m_HP->Destroy();
        }
    }*/
}

void CFirstSceneUI::Render()
{
    CUIWindow::Render();
}

CFirstSceneUI* CFirstSceneUI::Clone()
{
    return new CFirstSceneUI(*this);
}

void CFirstSceneUI::Save(FILE* File)
{
    CUIWindow::Save(File);
}

void CFirstSceneUI::Load(FILE* File)
{
    CUIWindow::Load(File);

    m_Button = FindWidget<CUIButton>("Button");
    m_Title = FindWidget<CUIText>("Title");
    m_Number = FindWidget<CUINumber>("Number");
    m_Back = FindWidget<CUIImage>("Back");
}

