#pragma once
#include "Node.h"
class CGrimmCurtain :
    public CNode
{
public:
    CGrimmCurtain();
    ~CGrimmCurtain();

private:
    CSharedPtr<class CPlayer2D>       m_Player;
    CSharedPtr<class CGrimm>          m_Grimm;
    class CScene*       m_Scene;
    CSharedPtr<CGrimmRandom>    m_Random;
    CSharedPtr<class CBat>	    m_Bat;

private:
    float   m_DelayTime;
    int     m_CountBat;
    bool    m_SpawnBatOn;

public:
    virtual bool Run();

    void SpawnBat();
};

