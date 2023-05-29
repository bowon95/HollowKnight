#pragma once

#include "Node.h"

// BeforeSpike - Spike
class CGrimmSpike :
    public CNode
{
public:
    CGrimmSpike();
    ~CGrimmSpike();

private:
    CSharedPtr<class CPlayer2D>       m_Player;
    CSharedPtr<class CGrimm>          m_Grimm;
    class CScene*         m_Scene;
    CSharedPtr<CGrimmRandom>    m_Random;

public:
    virtual bool Run();
};

