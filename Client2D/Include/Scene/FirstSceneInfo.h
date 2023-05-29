#pragma once

#include "Scene\SceneInfo.h"

class CFirstSceneInfo :
    public CSceneInfo
{
public:
    CFirstSceneInfo();
    ~CFirstSceneInfo();

private:
    CSharedPtr<class CUIImage>	m_Back;
    CSharedPtr<class CColliderBox2D> m_GroundCollider;
    CFade* m_Fade;

public:
    virtual void Start();
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void SceneChangeComplete();
};

