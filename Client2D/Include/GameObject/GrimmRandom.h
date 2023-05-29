#pragma once

#include "Node.h"

class CGrimmRandom :
    public CNode
{
public:
    CGrimmRandom();
    ~CGrimmRandom();

private:	
    CSharedPtr<class CGrimm>		m_Grimm;
    class CScene* m_Scene;

private:
    int     m_RandomNum;
    float   m_DelayTime;

    // 공격 패턴 변수.
    bool    m_GrimmBombOn;
    bool    m_GrimmSpikeOn;
    bool    m_GrimmToDiveOn;
    bool    m_GrimmCurtainOn;


public:
    void SetGrimmBombOn(bool GrimmBombOn)
    {
        m_GrimmBombOn = GrimmBombOn;
    }

    bool GetGrimmBombOn()
    {
        return m_GrimmBombOn;
    }

    void SetGrimmSpikeOn(bool GrimmSpikeOn)
    {
        m_GrimmSpikeOn = GrimmSpikeOn;
    }

    bool GetGrimmSpikeOn()
    {
        return m_GrimmSpikeOn;
    }

    void SetGrimmToDiveOn(bool GrimmToDiveOn)
    {
        m_GrimmToDiveOn = GrimmToDiveOn;
    }

    bool GetGrimmToDiveOn()
    {
        return m_GrimmToDiveOn;
    }

    void SetGrimmCurtainOn(bool GrimmCurtainOn)
    {
        m_GrimmCurtainOn = GrimmCurtainOn;
    }

    bool GetGrimmCurtainOn()
    {
        return m_GrimmCurtainOn;
    }

public:
    virtual bool Run();
};

