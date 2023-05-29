#pragma once

#include "Ref.h"
#include "Selector.h"
#include "Sequence.h"
#include "GrimmBomb.h"
#include "GrimmCurtain.h"
#include "GrimmDiveDash.h"
#include "GrimmSpike.h"
#include "GrimmRandom.h"

class CGrimmBT :
    public CRef
{
public:
    CGrimmBT();
    virtual ~CGrimmBT();

private:
	CSharedPtr<CSequence> m_Root;

	CSharedPtr<CSequence> m_Sequence1; // Random
	CSharedPtr<CSequence> m_Sequence2; 

	CSharedPtr<CSelector> m_Selector;

	CSharedPtr<CGrimmRandom> m_GrimmRandom;

	CSharedPtr<CGrimmBomb> m_GrimmBomb;
	CSharedPtr<CGrimmCurtain> m_GrimmCurtain;
	CSharedPtr<CGrimmDiveDash> m_GrimmDiveDash;
	CSharedPtr<CGrimmSpike> m_GrimmSpike;

public:
	void Start();
	void Run(bool IsRun = true);
};

