#pragma once

#include "Scene\SceneInfo.h"
#include "../UI/Fade.h"


class CSecondSceneInfo  :
    public CSceneInfo
{
public:
    CSecondSceneInfo();
    ~CSecondSceneInfo();

private:
    CSharedPtr<class CUIImage>	m_Back;
    CSharedPtr<class CSpriteComponent>  m_Sprite;
    CFade* m_Fade;

public:
    virtual void Start();
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void SceneChangeComplete();
};


