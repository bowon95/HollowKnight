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

    // Ű ���
    CInput::GetInst()->AddBindKey("Up", VK_UP);
    CInput::GetInst()->AddBindKey("Down", VK_DOWN);
    CInput::GetInst()->AddBindKey("Left", VK_LEFT);
    CInput::GetInst()->AddBindKey("Right", VK_RIGHT);

    CInput::GetInst()->AddBindKey("Jump", 'Z');
    CInput::GetInst()->AddBindKey("Attack", 'X');
    CInput::GetInst()->AddBindKey("Dash", 'C');
    CInput::GetInst()->AddBindKey("Focus/Cast", 'F'); // ����, ����

    CInput::GetInst()->AddBindKey("QuickMap", VK_TAB); // ��������
    CInput::GetInst()->AddBindKey("SuperDash", 'S'); // ���� ���
    CInput::GetInst()->AddBindKey("DreamNail", 'D'); // ��ȯ�� ���

    CInput::GetInst()->AddBindKey("QuickCast", 'A'); // ���� ����
    CInput::GetInst()->AddBindKey("Inventory", 'I'); // ����ǰ

    // SceneInfo ����
    //CSceneManager::GetInst()->CreateSceneInfo<CMainSceneInfo>();
    CSceneManager::GetInst()->GetScene()->Load("Start.scn", SCENE_PATH);
    return true;
}

int CClientManager::Run()
{
    return CEngine::GetInst()->Run();
}
