#include "GrimmBT.h"

CGrimmBT::CGrimmBT()
{
}

CGrimmBT::~CGrimmBT()
{
}

void CGrimmBT::Start()
{
	m_Root = new CSequence;

	m_Selector = new CSelector;

	m_Sequence1 = new CSequence;
	m_Sequence2 = new CSequence;


	m_GrimmRandom = new CGrimmRandom;
	m_GrimmBomb = new CGrimmBomb;
	//m_GrimmCurtain = new CGrimmCurtain;
	//m_GrimmDiveDash = new CGrimmDiveDash;
	//m_GrimmSpike = new CGrimmSpike;

	m_Root->AddChild(m_Selector);

	m_Selector->AddChild(m_Sequence1);
	m_Selector->AddChild(m_Sequence2);

	m_Sequence1->AddChild(m_GrimmRandom);
	
	m_Sequence2->AddChild(m_GrimmBomb);
	//m_Sequence2->AddChild(m_GrimmCurtain);
	//m_Sequence2->AddChild(m_GrimmDiveDash);
	//m_Sequence2->AddChild(m_GrimmSpike);
}

void CGrimmBT::Run(bool IsRun)
{
	m_Root->Run();
}
