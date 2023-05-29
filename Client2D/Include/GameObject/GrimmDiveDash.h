#pragma once
#include "Node.h"
class CGrimmDiveDash :
    public CNode

{
public:
    CGrimmDiveDash();
    ~CGrimmDiveDash();

private:
    CSharedPtr<CPlayer2D>       m_Player;
    CSharedPtr<CGrimm>          m_Grimm;
    class CScene*       m_Scene;
    CSharedPtr<CGrimmRandom>    m_Random;
    
private:
    float   m_DiveTime;
    bool    m_ToDiveOn;
    bool    m_DiveOn;

public:
    virtual bool Run();

private:
    void Dive();
};

