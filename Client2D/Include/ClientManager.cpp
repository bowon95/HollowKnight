#include "ClientManager.h"
#include "Scene/SceneManager.h"
#include "Scene/MainSceneInfo.h"
#include "Input.h"
#include "Setting/EngineShareSetting.h"

CClientManager::CClientManager()
{
}

CClientManager::~CClientManager()
{
    CEngine::DestroyInst();
}

bool CClientManager::Init(HINSTANCE hInst)
{
    if (!CEngine::GetInst()->Init(hInst, TEXT("Client2D"), TEXT("Client2D"), IDI_ICON1,
        IDI_ICON1, 1280, 720, 1280, 720, true))
    {
        return false;
    }

    CEngineShareSetting::Setting();

    // 키 등록
    CInput::GetInst()->AddBindKey("Up", VK_UP);
    CInput::GetInst()->AddBindKey("Down", VK_DOWN);
    CInput::GetInst()->AddBindKey("Left", VK_LEFT);
    CInput::GetInst()->AddBindKey("Right", VK_RIGHT);

    CInput::GetInst()->AddBindKey("Jump", 'Z');
    CInput::GetInst()->AddBindKey("Attack", 'X');
    CInput::GetInst()->AddBindKey("Dash", 'C');
    CInput::GetInst()->AddBindKey("Focus/Cast", 'F'); // 집중, 시전

    CInput::GetInst()->AddBindKey("QuickMap", VK_TAB); // 빠른지도
    CInput::GetInst()->AddBindKey("SuperDash", 'S'); // 슈퍼 대시
    CInput::GetInst()->AddBindKey("DreamNail", 'D'); // 몽환의 대못

    CInput::GetInst()->AddBindKey("QuickCast", 'A'); // 빠른 시전
    CInput::GetInst()->AddBindKey("Inventory", 'I'); // 소지품

    // SceneInfo 생성
    //CSceneManager::GetInst()->CreateSceneInfo<CMainSceneInfo>();
    CSceneManager::GetInst()->GetScene()->Load("Start.scn", SCENE_PATH);
    return true;
}

int CClientManager::Run()
{
    return CEngine::GetInst()->Run();
}
