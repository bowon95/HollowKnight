#include "LoadingSceneThread.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"
#include "PathManager.h"
#include "Thread/DataStream.h"
#include "EditorDefaultScene.h"
#include "FirstSceneInfo.h"
#include "SecondSceneInfo.h"
#include "DirtmouthSceneInfo.h"

CLoadingSceneThread::CLoadingSceneThread() :
	m_LoadComplete(false)
{
	m_PathName = SCENE_PATH;
}

CLoadingSceneThread::~CLoadingSceneThread()
{
}

void CLoadingSceneThread::Run()
{
	// Main Scene »ý¼º
	CSceneManager::GetInst()->CreateNextScene(false);

	if (m_NextScene == "EditorDefaultScene")
	{
		CSceneManager::GetInst()->CreateSceneInfo<CEditorDefaultScene>(false);
	}

	else if (m_NextScene == "FirstScene")
	{
		CSceneManager::GetInst()->CreateSceneInfo<CFirstSceneInfo>(false);
	}

	else if (m_NextScene == "SecondScene")
	{
		CSceneManager::GetInst()->CreateSceneInfo<CSecondSceneInfo>(false);
	}

	else if (m_NextScene == "Dirtmouth")
	{
		CSceneManager::GetInst()->CreateSceneInfo<CDirtmouthSceneInfo>(false);
	}

	CSceneManager::GetInst()->GetNextScene()->SetLoadingCallback<CLoadingSceneThread>(this, &CLoadingSceneThread::LoadingCallback);

	CSceneManager::GetInst()->GetNextScene()->Init();

	m_LoadComplete = true;
}

void CLoadingSceneThread::LoadingCallback(float Rate)
{
	unsigned char	Buffer[1024] = {};

	CDataStream	stream;
	stream.SetBuffer(Buffer);

	stream.AddData<float>(&Rate, 4);

	m_Queue.push((int)ELoadingSceneHeader::LoadingRate, stream.GetSize(),
		Buffer);

	//Sleep(200);
}
