#include "DefaultSetting.h"
#include "../GameObject/Player2D.h"
#include "../GameObject/Monster.h"
#include "../GameObject/Bullet.h"
#include "../GameObject/BackObj.h"
#include "../GameObject/WallObj.h"
#include "../GameObject/Effect.h"
#include "../GameObject/PortalObject.h"
#include "../GameObject/SecondPortal.h"
#include "../GameObject/Grimm.h"
#include "../GameObject/SecondBackObj.h"
#include "../GameObject/GrimmTroupeBackObj.h"
#include "../GameObject/GrimmChild.h"
#include "../GameObject/GrimmLandPoint.h"
#include "../GameObject/Elderbug.h"
#include "../GameObject/Spike.h"
#include "../UI/StartSceneUI.h"
#include "../UI/FirstSceneUI.h"
#include "../UI/SecondSceneUI.h"
#include "Scene/Scene.h"
#include "Input.h"
#include "CollisionManager.h"

CDefaultSetting::CDefaultSetting()
{
}

CDefaultSetting::~CDefaultSetting()
{
}

void CDefaultSetting::Init()
{
    LoadResource();

    CreateCDO();

    SetInput();

    SetCollision();
}

void CDefaultSetting::CreateCDO()
{
    CScene::CreateObjectCDO<CPlayer2D>("Player2D");
    CScene::CreateObjectCDO<CMonster>("Monster");
    CScene::CreateObjectCDO<CBullet>("Bullet");
    CScene::CreateObjectCDO<CBackObj>("BackObj");
    CScene::CreateObjectCDO<CWallObj>("WallObj");
    CScene::CreateObjectCDO<CSecondBackObj>("SecondBackObj");
    CScene::CreateObjectCDO<CEffect>("Effect");
    CScene::CreateObjectCDO<CPortalObject>("Portal");
    CScene::CreateObjectCDO<CSecondPortal>("SecondPortal");
    CScene::CreateObjectCDO<CGrimmLandPoint>("GrimmLandPoint");
    CScene::CreateObjectCDO<CGrimm>("Grimm");
    CScene::CreateObjectCDO<CGrimmTroupeBackObj>("GrimmTroupeBackObj");
    CScene::CreateObjectCDO<CGrimmChild>("GrimmChild");
    CScene::CreateObjectCDO<CElderbug>("Elderbug");
   // CScene::CreateObjectCDO<CSpike>("Spike");

    CScene::CreateUIWindowCDO<CStartSceneUI>("StartSceneUI");
    CScene::CreateUIWindowCDO<CFirstSceneUI>("FirstSceneUI");
    CScene::CreateUIWindowCDO<CSecondSceneUI>("SecondSceneUI");
}

void CDefaultSetting::LoadResource()
{
   
    // Idle
    {
        std::vector<const TCHAR*>   vecFileName;
    
        for (int i = 0; i <= 4; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];
    
            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);
    
            wsprintf(FileName, TEXT("Player/Idle/IdleLeft/Idle Wind_00%d.png"), i);
    
            vecFileName.push_back(FileName);
        }
    
        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "IdleLeft", "IdleLeft", vecFileName);
    
        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("IdleLeft",
            5, Vector2(0.f, 0.f), Vector2(349.f, 186.f));
    
        for (int i = 0; i <= 4; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    
        vecFileName.clear();
    
    
        for (int i = 4; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];
    
            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);
    
            wsprintf(FileName, TEXT("Player/Idle/IdleRight/Idle Wind_00%d.png"), i);
    
            vecFileName.push_back(FileName);
        }
    
        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "IdleRight", "IdleRight", vecFileName);
    
        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("IdleRight",
            5, Vector2(0.f, 0.f), Vector2(349.f, 186.f));
    
        for (int i = 4; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }

    // Left, Right
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 9; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Move/Left/Run_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "Left", "Left", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("Left",
            10, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 9; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();
    }

    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 9; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Move/Right/Run_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "Right", "Right", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("Right",
            10, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 9; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }
    // Up, Down
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 5; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/LookUp/Left/LookUp_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "UpLeft", "UpLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("UpLeft",
            6, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 5; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 5; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/LookUp/Right/LookUp_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "UpRight", "UpRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("UpRight",
            6, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 5; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }
    //
    {
        std::vector<const TCHAR*>   vecFileName;
        for (int i = 0; i <= 5; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/LookDown/Left/LookDown_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DownLeft", "DownLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DownLeft",
            6, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 5; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 5; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/LookDown/Right/LookDown_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DownRight", "DownRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DownRight",
            6, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 5; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }
    // Jump
    {
        std::vector<const TCHAR*>   vecFileName;
        for (int i = 0; i <= 5; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Jump/Left/Airborne_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "JumpLeft", "JumpLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("JumpLeft",
            6, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 5; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 5; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Jump/Right/Airborne_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "JumpRight", "JumpRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("JumpRight",
            6, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 5; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }
    // Dash
    {
        std::vector<const TCHAR*>   vecFileName;
        for (int i = 0; i <= 4; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Dash/Left/Dash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DashLeft", "DashLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DashLeft",
            5, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 4; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 4; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Dash/Right/Dash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DashRight", "DashRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DashRight",
            5, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 4; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }
    // Wounded
    CResourceManager::GetInst()->CreateAnimationSequence2D("WoundedLeft", "WoundedLeft", TEXT("WoundedLeft.png"));

    for (int i = 0; i < 5; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("WoundedLeft",
            Vector2(i * 132.2f, 0.f), Vector2((i + 1) * 132.2f, 121.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("WoundedRight", "WoundedRight", TEXT("WoundedRight.png"));

    for (int i = 0; i < 5; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("WoundedRight",
            Vector2(i * 132.2f, 0.f), Vector2((i + 1) * 132.2f, 121.f));
    }

    // Attack
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 7; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Slash/Left/NA Big Slash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "AttackLeft", "AttackLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("AttackLeft",
            8, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 7; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 7; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Slash/Right/NA Big Slash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "AttackRight", "AttackRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("AttackRight",
            8, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 7; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }
    // AttackUp
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 14; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Slash/Up/Left/UpSlash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "AttackUpLeft", "AttackUpLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("AttackUpLeft",
            15, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 14; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 14; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Slash/Up/Right/UpSlash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "AttackUpRight", "AttackUpRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("AttackUpRight",
            15, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 14; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }

    // AttackDown
    {
        std::vector<const TCHAR*>   vecFileName;
        for (int i = 0; i <= 14; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Slash/Down/Left/DownSlash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "AttackDownLeft", "AttackDownLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("AttackDownLeft",
            15, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 14; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 14; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Slash/Down/Right/DownSlash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "AttackDownRight", "AttackDownRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("AttackDownRight",
            15, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 14; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }

    // Double Jump
    {
        std::vector<const TCHAR*>   vecFileName;
        for (int i = 0; i <= 7; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/DoubleJump/Left/Double Jump_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DoubleJumpLeft", "DoubleJumpLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DoubleJumpLeft",
            8, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 7; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 7; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/DoubleJump/Right/Double Jump_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DoubleJumpRight", "DoubleJumpRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DoubleJumpRight",
            8, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 7; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }

    // Death
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 17; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Death/Left/Death_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DeathLeft", "DeathLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DeathLeft",
            18, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 17; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 17; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Death/Right/Death_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DeathRight", "DeathRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DeathRight",
            18, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 17; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }

    // Focus
    {
        std::vector<const TCHAR*>   vecFileName;
        for (int i = 0; i <= 6; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Focus/Left/Focus_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "FocusLeft", "FocusLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("FocusLeft",
            7, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 6; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 6; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Focus/Right/Focus_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "FocusRight", "FocusRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("FocusRight",
            7, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 6; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }

    // Fall
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 5; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Fall/Left/Airborne_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "FallLeft", "FallLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("FallLeft",
            6, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 5; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 5; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Fall/Right/Airborne_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "FallRight", "FallRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("FallRight",
            6, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 5; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }

    // Shadow
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 3; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Dash/Shadow/Left/Shadow Dash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "ShadowDashLeft", "ShadowDashLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("ShadowDashLeft",
            4, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 0; i <= 3; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 3; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Player/Dash/Shadow/Right/Shadow Dash_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "ShadowDashRight", "ShadowDashRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("ShadowDashRight",
            4, Vector2(0.f, 0.f), Vector2(349.f, 186.f));

        for (int i = 3; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }

    //============================================= Monster ===========================================================//

    // Idle
    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterIdleLeft", "MonsterIdleLeft", TEXT("Monster/IdleLeft.png"));

    for (int i = 0; i < 6; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterIdleLeft",
            Vector2(i * 121.f, 0.f), Vector2((i + 1) * 121.f, 198.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterIdleRight", "MonsterIdleRight", TEXT("Monster/IdleRight.png"));

    for (int i = 0; i < 6; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterIdleRight",
            Vector2(i * 121.f, 0.f), Vector2((i + 1) * 121.f, 198.f));
    }

    // Left, Right
    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterLeft", "MonsterLeft", TEXT("Monster/Left.png"));

    for (int i = 0; i < 7; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterLeft",
            Vector2(i * 141.857f, 0.f), Vector2((i + 1) * 141.857f, 190.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterRight", "MonsterRight", TEXT("Monster/Right.png"));

    for (int i = 0; i < 7; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterRight",
            Vector2(i * 141.857f, 0.f), Vector2((i + 1) * 141.857f, 190.f));
    }

    // Attack
    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterAttackLeft", "MonsterAttackLeft", TEXT("Monster/AttackLeft.png"));

    for (int i = 0; i < 5; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterAttackLeft",
            Vector2(i * 174.f, 0.f), Vector2((i + 1) * 174.f, 190.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterAttackRight", "MonsterAttackRight", TEXT("Monster/AttackRight.png"));

    for (int i = 0; i < 5; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterAttackRight",
            Vector2(i * 174.f, 0.f), Vector2((i + 1) * 174.f, 190.f));
    }

    // Dash
    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterDashLeft", "MonsterDashLeft", TEXT("Monster/DashLeft.png"));

    for (int i = 0; i < 4; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterDashLeft",
            Vector2(i * 185.25f, 0.f), Vector2((i + 1) * 185.25f, 119.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterDashRight", "MonsterDashRight", TEXT("Monster/DashRight.png"));

    for (int i = 0; i < 4; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterDashRight",
            Vector2(i * 185.25f, 0.f), Vector2((i + 1) * 185.25f, 119.f));
    }

    // Land
    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterLandLeft", "MonsterLandLeft", TEXT("Monster/LandLeft.png"));

    for (int i = 0; i < 5; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterLandLeft",
            Vector2(i * 192.8f, 0.f), Vector2((i + 1) * 192.8f, 127.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("MonsterLandRight", "MonsterLandRight", TEXT("Monster/LandRight.png"));

    for (int i = 0; i < 5; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MonsterLandRight",
            Vector2(i * 192.8f, 0.f), Vector2((i + 1) * 192.8f, 127.f));
    }

    //============================================= Effect ===========================================================//
    
    CResourceManager::GetInst()->CreateAnimationSequence2D("SlashLeft", "SlashLeft", TEXT("SlashLeft.png"));

    for (int i = 0; i < 4; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("SlashLeft",
            Vector2(i * 157.f, 0.f), Vector2((i + 1) * 157.f, 114.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("SlashRight", "SlashRight", TEXT("SlashRight.png"));

    for (int i = 0; i < 4; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("SlashRight",
            Vector2(i * 157.f, 0.f), Vector2((i + 1) * 157.f, 114.f));
    }



    CResourceManager::GetInst()->CreateAnimationSequence2D("AttackDownLeftEffect", "AttackDownLeftEffect", TEXT("AttackDownLeftEffect.png"));

    for (int i = 0; i < 4; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("AttackDownLeftEffect",
            Vector2(i * 183.f, 0.f), Vector2((i + 1) * 183.f, 210.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("AttackDownRightEffect", "AttackDownRightEffect", TEXT("AttackDownRightEffect.png"));

    for (int i = 3; i >= 0; --i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("AttackDownRightEffect",
            Vector2(i * 183.f, 0.f), Vector2((i + 1) * 183.f, 210.f));
    }


    CResourceManager::GetInst()->CreateAnimationSequence2D("AttackUpLeftEffect", "AttackUpLeftEffect", TEXT("AttackUpLeftEffect.png"));

    for (int i = 0; i < 4; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("AttackUpLeftEffect",
            Vector2(i * 170.f, 0.f), Vector2((i + 1) * 170.f, 189.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("AttackUpRightEffect", "AttackUpRightEffect", TEXT("AttackUpRightEffect.png"));

    for (int i = 3; i >= 0; --i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("AttackUpRightEffect",
            Vector2(i * 170.f, 0.f), Vector2((i + 1) * 170.f, 189.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("DashLeftEffect", "DashLeftEffect", TEXT("DashLeftEffect.png"));

    for (int i = 0; i < 6; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("DashLeftEffect",
            Vector2(i * 424.f, 0.f), Vector2((i + 1) * 424.f, 236.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("DashRightEffect", "DashRightEffect", TEXT("DashRightEffect.png"));

    for (int i = 0; i < 6; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("DashRightEffect",
            Vector2(i * 424.f, 0.f), Vector2((i + 1) * 424.f, 236.f));
    }

    // Focus Effect
    CResourceManager::GetInst()->CreateAnimationSequence2D("FocusEffect", "FocusEffect", TEXT("FocusEffect.png"));

    for (int i = 0; i < 13; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("FocusEffect",
            Vector2(i * 91.f, 0.f), Vector2((i + 1) * 91.f, 182.f));
    }

    // Light
    CResourceManager::GetInst()->CreateAnimationSequence2D("Light", "Light", TEXT("Grimm/Light.png"));

    for (int i = 0; i < 2; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("Light",
            Vector2(i * 2048.f, 0.f), Vector2((i + 1) * 2048.f, 1228.f));
    }

    // GrimmChildInEffect
    CResourceManager::GetInst()->CreateAnimationSequence2D("GrimmChildInEffect", "GrimmChildInEffect", TEXT("Grimm/GrimmChildInEffect.png"));

    for (int i = 0; i < 4; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("GrimmChildInEffect",
            Vector2(i * 283.5f, 0.f), Vector2((i + 1) * 283.5f, 189.f));
    }

    // FireBalls
    CResourceManager::GetInst()->CreateAnimationSequence2D("FireBalls", "FireBalls", TEXT("Grimm/FireBalls.png"));

    for (int i = 0; i < 8; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("FireBalls",
            Vector2(i * 94.5f, 0.f), Vector2((i + 1) * 94.5f, 95.f));
    }

    // MiniSpike
    CResourceManager::GetInst()->CreateAnimationSequence2D("MiniSpike", "MiniSpike", TEXT("Grimm/MiniSpike.png"));

    for (int i = 0; i < 5; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("MiniSpike",
            Vector2(i * 94.6f, 0.f), Vector2((i + 1) * 94.6f, 165.f));
    }

    // LongSpike
    CResourceManager::GetInst()->CreateAnimationSequence2D("LongSpike", "LongSpike", TEXT("Grimm/LongSpike.png"));

    for (int i = 0; i < 8; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("LongSpike",
            Vector2(i * 94.4f, 0.f), Vector2((i + 1) * 94.4f, 580.f));
    }



    //============================================ HP=====================================================//
    CResourceManager::GetInst()->CreateAnimationSequence2D("HPFull", "HPFull", TEXT("HP.png"));

    for (int i = 0; i < 7; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("HPFull",
            Vector2(i * 57.f, 0.f), Vector2((i + 1) * 57.f, 70.f));
    }



    //======================================== Bat ==================================================//
    CResourceManager::GetInst()->CreateAnimationSequence2D("GrimmFireRight", "GrimmFireRight", TEXT("Grimm/Bat/GrimmFireRight.png"));

    for (int i = 0; i < 4; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("GrimmFireRight",
            Vector2(i * 258.f, 0.f), Vector2((i + 1) * 258.f, 226.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("GrimmFireLeft", "GrimmFireLeft", TEXT("Grimm/Bat/GrimmFireLeft.png"));

    for (int i = 3; i >= 0; --i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("GrimmFireLeft",
            Vector2(i * 258.f, 0.f), Vector2((i + 1) * 258.f, 226.f));
    }

    //======================================== GrimmChild ==================================================//

    CResourceManager::GetInst()->CreateAnimationSequence2D("GrimmChildLeft", "GrimmChildLeft", TEXT("GrimmChildLeft.png"));

    for (int i = 0; i < 7; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("GrimmChildLeft",
            Vector2(i * 174.f, 0.f), Vector2((i + 1) * 174.f, 158.f));
    }

    CResourceManager::GetInst()->CreateAnimationSequence2D("GrimmChildRight", "GrimmChildRight", TEXT("GrimmChildRight.png"));

    for (int i = 5; i >= 0; --i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("GrimmChildRight",
            Vector2(i * 174.f, 0.f), Vector2((i + 1) * 174.f, 158.f));
    }
    //======================================== Grimm ==================================================//

    // Start
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 41; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/BeforeAttack/GrimmAppear/Grimm Cln_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "First_GrimmAppear", "First_GrimmAppear", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("First_GrimmAppear",
            42, Vector2(0.f, 0.f), Vector2(264.f, 441.f));

        for (int i = 0; i <= 41; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();

    }

    // GrimmStretch
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 8; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/BeforeAttack/GrimmStretch/Absorb Start_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "GrimmStretch", "GrimmStretch", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("GrimmStretch",
            9, Vector2(0.f, 0.f), Vector2(546.f, 816.f));

        for (int i = 0; i <= 8; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();
    }

    // GrimmAbsorb1
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 4; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/BeforeAttack/GrimmAbsorb1/Absorb_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "GrimmAbsorb1", "GrimmAbsorb1", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("GrimmAbsorb1",
            5, Vector2(0.f, 0.f), Vector2(546.f, 816.f));

        for (int i = 0; i <= 4; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();

    }

    // GrimmAbsorb2
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 7; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/BeforeAttack/GrimmAbsorb2/Absorb_00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "GrimmAbsorb2", "GrimmAbsorb2", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("GrimmAbsorb2",
            8, Vector2(0.f, 0.f), Vector2(390.f, 508.f));

        for (int i = 0; i <= 7; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();

    }
  
    // GrimmRoar
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 2; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/BeforeAttack/GrimmRoar/Roar00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "GrimmRoar", "GrimmRoar", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("GrimmRoar",
            3, Vector2(0.f, 0.f), Vector2(514.f, 438.f));

        for (int i = 0; i <= 2; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();

    }

    // GrimmBomb
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 3; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/Bomb/Bomb00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "GrimmBomb", "GrimmBomb", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("GrimmBomb",
            4, Vector2(0.f, 0.f), Vector2(521.f, 576.f));

        for (int i = 0; i <= 3; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();

    }

    // FireBalls
    CResourceManager::GetInst()->CreateAnimationSequence2D("FireBalls", "FireBalls", TEXT("Grimm/FireBalls/FireBalls.png"));

    for (int i = 0; i < 8; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("FireBalls",
            Vector2(i * 94.5f, 0.f), Vector2((i + 1) * 94.5f, 95.f));
    }

    // ToSpike
    CResourceManager::GetInst()->CreateAnimationSequence2D("GrimmToSpike", "GrimmToSpike", TEXT("Grimm/ToSpike/GrimmToSpike.png"));

    for (int i = 0; i < 7; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("GrimmToSpike",
            Vector2(i * 400.16f, 0.f), Vector2((i + 1) * 400.16f, 414.f));
    }

    // Spike
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 2; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/Spike/GrimmSpike00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "GrimmSpike", "GrimmSpike", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("GrimmSpike",
            3, Vector2(0.f, 0.f), Vector2(394.f, 445.f));

        for (int i = 0; i <= 2; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();
    }

    // ToDive
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 5; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/ToDive/Left/HitDownLeft00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "ToDiveLeft", "ToDiveLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("ToDiveLeft",
            6, Vector2(0.f, 0.f), Vector2(900.f, 525.f));

        for (int i = 0; i <= 5; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();
    }

    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 5; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/ToDive/Right/HitDownRight00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "ToDiveRight", "ToDiveRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("ToDiveRight",
            6, Vector2(0.f, 0.f), Vector2(900.f, 786.f));

        for (int i = 0; i <= 5; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();
    }

    // Dive
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 1; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/Dive/Left/HitDownLeft00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DiveLeft", "DiveLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DiveLeft",
            2, Vector2(0.f, 0.f), Vector2(900.f, 525.f));

        for (int i = 0; i <= 1; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();
    }

    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 1; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/Dive/Right/HitDownRight00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "DiveRight", "DiveRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("DiveRight",
            2, Vector2(0.f, 0.f), Vector2(900.f, 786.f));

        for (int i = 0; i <= 1; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();
    }

    // Curtain
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 7; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/Curtain/Left/Cast00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "CurtainLeft", "CurtainLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("CurtainLeft",
            8, Vector2(0.f, 0.f), Vector2(546.f, 444.f));

        for (int i = 0; i <= 7; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();


        for (int i = 7; i >= 0; --i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/Curtain/Right/Cast00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "CurtainRight", "CurtainRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("CurtainRight",
            8, Vector2(0.f, 0.f), Vector2(546.f, 444.f));

        for (int i = 7; i >= 0; --i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }
    }

    // Dash
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 11; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/Dash/Left/GrimmDashLeft00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "GrimmDashLeft", "GrimmDashLeft", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("GrimmDashLeft",
            12, Vector2(0.f, 0.f), Vector2(900.f, 786.f));

        for (int i = 0; i <= 11; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();

    }

    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 11; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/Dash/Right/GrimmDashRight00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "GrimmDashRight", "GrimmDashRight", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("GrimmDashRight",
            12, Vector2(0.f, 0.f), Vector2(900.f, 786.f));

        for (int i = 0; i <= 11; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();

    }

    // Disappear
    {
        std::vector<const TCHAR*>   vecFileName;

        for (int i = 0; i <= 6; ++i)
        {
            TCHAR* FileName = new TCHAR[MAX_PATH];

            memset(FileName, 0, sizeof(TCHAR) * MAX_PATH);

            wsprintf(FileName, TEXT("Grimm/Disappear/Disappear00%d.png"), i);

            vecFileName.push_back(FileName);
        }

        CResourceManager::GetInst()->CreateAnimationSequence2D(
            "Disappear", "Disappear", vecFileName);

        CResourceManager::GetInst()->AddAnimationSequence2DFrameAll("Disappear",
            7, Vector2(0.f, 0.f), Vector2(514.f, 438.f));

        for (int i = 0; i <= 6; ++i)
        {
            SAFE_DELETE_ARRAY(vecFileName[i]);
        }

        vecFileName.clear();

    }

    //======================================== NPC ==================================================//

    // Elderbug
    // Idle
    CResourceManager::GetInst()->CreateAnimationSequence2D("ElderbugIdle", "ElderbugIdle", TEXT("ElderbugIdle.png"));

    for (int i = 0; i < 6; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("ElderbugIdle",
            Vector2(i * 124.f, 0.f), Vector2((i + 1) * 124.f, 172.f));
    }

    // Bye
    CResourceManager::GetInst()->CreateAnimationSequence2D("ElderbugBye", "ElderbugBye", TEXT("ElderbugBye.png"));

    for (int i = 0; i < 8; ++i)
    {
        CResourceManager::GetInst()->AddAnimationSequence2DFrame("ElderbugBye",
            Vector2(i * 124.f, 0.f), Vector2((i + 1) * 124.f, 172.f));
    }

    //=================== Sound =========================//
    //CResourceManager::GetInst()->LoadSound("Effect", "dark-crystal-step-01", false,"dark-crystal-step-01.ogg");

    CResourceManager::GetInst()->LoadSound("BGM", "Grimm", true, "Grimm.mp3");
    CResourceManager::GetInst()->LoadSound("BGM", "Start", true, "Start.mp3");

    CResourceManager::GetInst()->LoadSound("BGM", "CrossRoads", true, "CrossRoads.mp3");
    CResourceManager::GetInst()->LoadSound("BGM", "CityOfTears", true, "CityOfTears.mp3");



    //CResourceManager::GetInst()->LoadSound("Effect", "Demasia", true, "Demasia.mp3");



}

void CDefaultSetting::SetInput()
{
    // 키 등록

    CInput::GetInst()->AddBindKey("Up", VK_UP);
    CInput::GetInst()->AddBindKey("Down", VK_DOWN);
    CInput::GetInst()->AddBindKey("Left", VK_LEFT);
    CInput::GetInst()->AddBindKey("Right", VK_RIGHT);


    CInput::GetInst()->AddBindKey("Jump", 'Z');
    CInput::GetInst()->AddBindKey("Attack", 'X');
    CInput::GetInst()->AddBindKey("Dash", 'C');
    CInput::GetInst()->AddBindKey("Focus/Cast", 'A'); // 집중, 시전

    CInput::GetInst()->AddBindKey("QuickMap", VK_TAB); // 빠른지도
    CInput::GetInst()->AddBindKey("SuperDash", 'S'); // 슈퍼 대시
    CInput::GetInst()->AddBindKey("DreamNail", 'D'); // 몽환의 대못

    CInput::GetInst()->AddBindKey("QuickCast", 'O'); // 빠른 시전
    CInput::GetInst()->AddBindKey("Inventory", 'I'); // 소지품


    CInput::GetInst()->AddBindKey("Test", 'H');

    CInput::GetInst()->AddBindKey("EndGame", 'J');
}


void CDefaultSetting::SetCollision()
{
    CCollisionManager::GetInst()->CreateChannel("Player", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("PlayerAttack", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("Monster", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("MonsterAttack", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("Wall", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("PlayerEffect", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("Portal", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("MonsterRange", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("GrimmChild", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("GrimmLandPoint", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("Effect", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("NPC", ECollision_Interaction::Collision);
    CCollisionManager::GetInst()->CreateChannel("Ground", ECollision_Interaction::Collision);

    CCollisionManager::GetInst()->CreateProfile("Player", "Player", true);
    CCollisionManager::GetInst()->CreateProfile("PlayerAttack", "PlayerAttack", true);
    CCollisionManager::GetInst()->CreateProfile("Monster", "Monster", true);
    CCollisionManager::GetInst()->CreateProfile("MonsterAttack", "MonsterAttack", true);
    CCollisionManager::GetInst()->CreateProfile("Wall", "Wall", true);
    CCollisionManager::GetInst()->CreateProfile("PlayerEffect", "PlayerEffect", true);
    CCollisionManager::GetInst()->CreateProfile("Portal", "Portal", true);
    CCollisionManager::GetInst()->CreateProfile("MonsterRange", "MonsterRange", true);
    CCollisionManager::GetInst()->CreateProfile("GrimmChild", "GrimmChild", true);
    CCollisionManager::GetInst()->CreateProfile("GrimmLandPoint", "GrimmLandPoint", true);
    CCollisionManager::GetInst()->CreateProfile("Effect", "Effect", true);
    CCollisionManager::GetInst()->CreateProfile("NPC", "NPC", true);
    CCollisionManager::GetInst()->CreateProfile("Ground", "Ground", true);

    CCollisionManager::GetInst()->SetCollisionInteraction("Player", "PlayerAttack", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("Player", "Player", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("PlayerAttack", "Player", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("PlayerAttack", "MonsterAttack", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("PlayerAttack", "PlayerAttack", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("Monster", "MonsterAttack", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("Monster", "Monster", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("MonsterAttack", "Monster", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("MonsterAttack", "MonsterAttack", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("MonsterAttack", "PlayerAttack", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("Wall", "Wall", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("PlayerEffect", "PlayerEffect", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("Portal", "Portal", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("MonsterRange", "MonsterRange", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("GrimmChild", "GrimmChild", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("GrimmLandPoint", "GrimmLandPoint", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("Effect", "Effect", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("Monster", "Portal", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("Portal", "Monster", ECollision_Interaction::Ignore);

    CCollisionManager::GetInst()->SetCollisionInteraction("NPC", "NPC", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("NPC", "Effect", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("Effect", "NPC", ECollision_Interaction::Ignore);
    CCollisionManager::GetInst()->SetCollisionInteraction("Ground", "Ground", ECollision_Interaction::Ignore);
}

