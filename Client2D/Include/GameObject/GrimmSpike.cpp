#include "GrimmSpike.h"
#include "Scene/Scene.h"
#include "Player2D.h"
#include "Grimm.h"
#include "GrimmRandom.h"
#include "Spike.h"

CGrimmSpike::CGrimmSpike()	
{
}

CGrimmSpike::~CGrimmSpike()
{
}

bool CGrimmSpike::Run()
{
	if (!m_Random->GetGrimmSpikeOn())
		return false;

	m_Grimm->SpikeAnim();
	m_Grimm->SetDrawOn(false);


    return true;
}

