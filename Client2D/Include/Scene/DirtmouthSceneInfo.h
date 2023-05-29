#pragma once

#include "Scene\SceneInfo.h"

class CDirtmouthSceneInfo   :
    public CSceneInfo
{
    public:
        CDirtmouthSceneInfo();
        ~CDirtmouthSceneInfo();

    private:
        CSharedPtr<class CUIImage>	m_Back;
        CSharedPtr<class CPlayer2D>	m_Player;
        CSharedPtr<class CGrimm>	m_Grimm;
        CSharedPtr<class CGrimmChild>	m_GrimmChild;
        CSharedPtr<class CEffect>   m_Effect;
        class CFade* m_Fade;


    public:
        virtual void Start();
        virtual bool Init();
        virtual void Update(float DeltaTime);
        virtual void SceneChangeComplete();
};

