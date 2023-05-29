#pragma once

#include "Node.h"

class CGrimmBomb :
    public CNode
{
public:
    CGrimmBomb();
    ~CGrimmBomb();

private:
    CSharedPtr<class CGrimm>          m_Grimm;
    class CScene*         m_Scene;
    CSharedPtr<class CGrimmRandom>    m_Random;
    class CBullet* m_FireBalls[15];


private:
    float   m_DelayTime;
    int     m_CountBomb;

public:
    virtual bool Run();

private:
    void FireBalls();
};

